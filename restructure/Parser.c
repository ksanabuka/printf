//
//  Parser.c
//  printf
//
//  Created by Oksana Buksha on 6/8/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include "Parser.h"
#include <unistd.h>
#include "libft.h"
#include "PrintTypeInfo.h"
#include "IntPrintTypeInfo.h"
#include "UIntPrintTypeInfo.h"
#include "StringPrintTypeInfo.h"

enum PrintType {
    PT_INT = 0,
    PT_UINT = 1,
    PT_STR = 2,
    PT_CHAR = 3,
    PT_PTR = 4,
    PT_REAL = 5
};

int print_value(void *value, enum PrintType type, const struct FormatParams *fmt_params) {
    struct FormattedPrintTypeInfo formatted;
    struct PrintTypeInfo info;
    int res;
    
    if (type == PT_INT)
        info = create_int_print_type_info(value, fmt_params);
    else if (type == PT_UINT)
        info = create_uint_print_type_info(value, fmt_params);
    else if (type == PT_STR)
        info = create_str_print_type_info(value, fmt_params);
    else
        return 0;
    
    formatted = create_formatted_print_type_info(&info, fmt_params);
    res = print_formatted_type_info(&formatted);
    cleanup_formatted_print_type_info(&formatted);
    
    return res;
}

struct ParserState {
    const char *fmt;
    va_list list;
    
};

int read_flags(struct ParserState *state)
{
    int flags;

    flags = 0;
    while (1)
    {
        if (*state->fmt == ' ')
            flags |= F_SPACE;
        else if (*state->fmt == '0')
            flags |= F_ZERO;
        else if (*state->fmt == '-')
            flags |= F_MINUS;
        else if (*state->fmt == '+')
            flags |= F_PLUS;
        else if (*state->fmt == '#')
            flags |= F_DIEZ;
        else
            break;
        ++state->fmt;
    }
    return flags;
}

int read_width_or_precision_value(struct ParserState *state)
{
    int w = 0;
    
    if (*state->fmt == '*')
    {
        ++state->fmt;
        w = va_arg(state->list, int);
    }
    else
    {
        while (*state->fmt >= '0' && *state->fmt <= '9')
        {
            w = 10 * w + (*state->fmt - '0');
            ++state->fmt;
        }
    }
    return w;
}

int read_width(struct ParserState *state)
{
    return read_width_or_precision_value(state);
}

int read_precision(struct ParserState *state)
{
    int p = -1;
    if (*state->fmt == '.')
    {
        ++state->fmt;
        p = read_width_or_precision_value(state);
    }
    return p;
}

enum LenModifier read_len_modifier(struct ParserState *state)
{
    if (state->fmt[0] == 'l' || state->fmt[0] == 'L')
    {
        return state->fmt[1] == 'l' || state->fmt[1] == 'L' ? LM_LL : LM_L;
    }
    if (state->fmt[0] == 'h')
    {
        return state->fmt[1] == 'h' ? LM_HH : LM_H;
    }
    return LM_DEFAULT;
}

static struct FormatParams read_format_params(struct ParserState *state, int int_base, int is_prefix_uppercase)
{
    // flags width . precision length
    struct FormatParams res;
    res.flags = read_flags(state);
    res.width = read_width(state);
    res.precision = read_precision(state);
    res.lenModifier = read_len_modifier(state);
    res.int_base = int_base;
    res.is_prefix_uppercase = is_prefix_uppercase;
    return res;
}

long long read_int_value(struct ParserState *state, enum LenModifier lenModifier)
{
    long long value;

    value = 0;
    
    if (lenModifier == LM_LL)
        value = va_arg(state->list, long long);
    else if (lenModifier == LM_L)
        value = va_arg(state->list, long);
    else if (lenModifier == LM_H)
        value = (short)va_arg(state->list, int);
    else if (lenModifier == LM_HH)
        value = (char)va_arg(state->list, int);
    else
        value = va_arg(state->list, int);
    
    return value;
}

int print_int(struct ParserState *state)
{
    struct FormatParams params;
    long long value;

    params = read_format_params(state, 10, 0);
    value = read_int_value(state, params.lenModifier);
    return print_value(&value, PT_INT, &params);
}

unsigned long long read_uint_value(struct ParserState *state, enum LenModifier lenModifier)
{
    unsigned long long value;
    
    value = 0;
    
    if (lenModifier == LM_LL)
        value = va_arg(state->list, unsigned long long);
    else if (lenModifier == LM_L)
        value = va_arg(state->list, unsigned long);
    else if (lenModifier == LM_H)
        value = (unsigned short)va_arg(state->list, unsigned int);
    else if (lenModifier == LM_HH)
        value = (unsigned char)va_arg(state->list, unsigned int);
    else
        value = va_arg(state->list, unsigned int);
    
    return value;
}

int print_uint(struct ParserState *state, int base, int uppercase)
{
    struct FormatParams params;
    unsigned long long value;
    
    params = read_format_params(state, base, uppercase);
    value = read_uint_value(state, params.lenModifier);
    return print_value(&value, PT_UINT, &params);
}

int print_char(struct ParserState *state)
{
    struct FormatParams params;
    params = read_format_params(state, 10, 0);
    char c = (char)va_arg(state->list, int);
    write(1, &c, 1);
    return 1;
}

int print_str(struct ParserState *state)
{
    struct FormatParams params;
    char *value;
    
    params = read_format_params(state, 10, 0);
    value = va_arg(state->list, char *);
    return print_value(value, PT_STR, &params);
}

int print_ptr(struct ParserState *state)
{
    struct FormatParams params;
    unsigned long long value;
    void *ptr;

    params = read_format_params(state, 16, 0);
    params.flags |= F_DIEZ;
    params.lenModifier = LM_LL;
    ptr = va_arg(state->list, void *);
    value = (unsigned long long)ptr;
    return print_value(&value, PT_UINT, &params);
}

int print_real(struct ParserState *state)
{
    struct FormatParams params;
    params = read_format_params(state, 10, 0);
    return 0;
}

int try_print_type(struct ParserState *state, const char *pos)
{
    int numPrinted = -1;
    if (*pos == 'd' || *pos == 'i')
        numPrinted = print_int(state);
    else if (*pos == 'c')
        numPrinted = print_char(state);
    else if (*pos == 's')
        numPrinted = print_str(state);
    else if (*pos == 'p')
        numPrinted = print_ptr(state);
    else if (*pos == 'f' || *pos == 'F')
        numPrinted = print_real(state);
    else if (*pos == 'o'|| *pos == 'O')
        numPrinted = print_uint(state, 8, 0);
    else if (*pos == 'x' || *pos == 'X')
        numPrinted = print_uint(state, 16, *pos == 'X');
    else if (*pos == 'b'|| *pos == 'B')
        numPrinted = print_uint(state, 2, 0);
    else if (*pos == 'u' || *pos == 'U')
        numPrinted = print_uint(state, 10, 0);
    return numPrinted;
}

int print_single_type(struct ParserState *state)
{
    const char *pos;
    int numPrinted;

    pos = state->fmt;
    numPrinted = -1;
    while (*pos && numPrinted < 0)
    {
        numPrinted = try_print_type(state, pos);
        ++pos;
    }
    if (numPrinted >= 0)
        state->fmt = pos;
    else
    {
        numPrinted = 0;
        while (*state->fmt)
        {
            write(1, state->fmt, 1);
            ++state->fmt;
            ++numPrinted;
        }
    }
    return numPrinted;
}

int ft_printf(const char *fmt, ...)
{
    struct ParserState state;
    state.fmt = fmt;
    int numPrinted = 0;
    
    va_start(state.list, fmt);
    
    while (*state.fmt) {
        if (*state.fmt == '%') {
            ++state.fmt;
            if (*state.fmt == '%') {
                write(1, state.fmt, 1);
                ++numPrinted;
                ++state.fmt;
            } else {
                numPrinted += print_single_type(&state);
            }
        } else {
            write(1, state.fmt, 1);
            ++numPrinted;
            ++state.fmt;
        }
    }
    
    va_end(state.list);
    
    return numPrinted;
}
