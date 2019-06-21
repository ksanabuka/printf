/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:19 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:23 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"
#include "double_print_type_info.h"
#include "int_print_type_info.h"
#include "string_print_type_info.h"
#include "uint_print_type_info.h"
#include "char_print_type_info.h"

int print_val(void *val, enum e_print_type type, t_fmt_pms *fmt_prm)
{
	struct formatted_pti formatted;
	t_pti info;
	int res;
	
	if (type == PT_INT)
		info = create_intpti(val, fmt_prm);
	else if (type == PT_UINT)
		info = create_uintpti(val, fmt_prm);
	else if (type == PT_STR)
		info = create_strpti(val, fmt_prm);
	else if (type == PT_REAL)
		info = create_realpti(val, fmt_prm);
	else if (type == PT_CHAR)
		info = create_charpti(val, fmt_prm);
	else
		return (0);
	
	formatted = create_formattedpti(&info, fmt_prm);
	res = print_formatted_type_info(&formatted);
	cleanup_formattedpti(&formatted);
	
	return (res);
}

struct ParserState
{
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
			break ;
		++state->fmt;
	}

	return flags;
}

int read_width_or_preci_val(struct ParserState *state)
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
	return read_width_or_preci_val(state);
}

int read_preci(struct ParserState *state)
{
	int p = -1;
	if (*state->fmt == '.')

{
		++state->fmt;
		p = read_width_or_preci_val(state);
	}

	return p;
}

enum e_len_modifier read_len_modifier(struct ParserState *state)
{
	if (state->fmt[0] == 'l' || state->fmt[0] == 'L')

{
		if (state->fmt[0] == 'L')
			return LM_CL;
		return state->fmt[1] == 'l' || state->fmt[1] == 'L' ? LM_LL : LM_L;
	}

	if (state->fmt[0] == 'h')
		return state->fmt[1] == 'h' ? LM_HH : LM_H;
	if (state->fmt[0] == 'z')
{
		if (sizeof(size_t) == sizeof(long))
			return LM_L;
		else if (sizeof(size_t) == sizeof(long long))
			return LM_LL;
	}

	if (state->fmt[0] == 'j')
{
		if (sizeof(intmax_t) == sizeof(long))
			return LM_L;
		else if (sizeof(intmax_t) == sizeof(long long))
			return LM_LL;
	}

	
	return LM_DEFAULT;
}

static t_fmt_pms read_format_params(struct ParserState *state, int int_base, int is_prfx_uppercase)
{
	// flags width . preci length
	t_fmt_pms res;
	res.flags = read_flags(state);
	res.width = read_width(state);
	res.preci = read_preci(state);
	res.len_modifier = read_len_modifier(state);
	res.int_base = int_base;
	res.is_prfx_uppercase = is_prfx_uppercase;
	return (res);
}

long long read_int_val(struct ParserState *state, enum e_len_modifier len_modifier)
{
	long long val;
	val = 0;
	
	if (len_modifier == LM_LL)
		val = va_arg(state->list, long long);
	else if (len_modifier == LM_L)
		val = va_arg(state->list, long);
	else if (len_modifier == LM_H)
		val = (short)va_arg(state->list, int);
	else if (len_modifier == LM_HH)
		val = (char)va_arg(state->list, int);
	else
		val = va_arg(state->list, int);
	
	return val;
}

int print_int(struct ParserState *state)
{
	t_fmt_pms params;
	long long val;
	params = read_format_params(state, 10, 0);
	val = read_int_val(state, params.len_modifier);
	return print_val(&val, PT_INT, &params);
}

unsigned long long read_uint_val(struct ParserState *state, enum e_len_modifier len_modifier)
{
	unsigned long long val;
	
	val = 0;
	
	if (len_modifier == LM_LL)
		val = va_arg(state->list, unsigned long long);
	else if (len_modifier == LM_L)
		val = va_arg(state->list, unsigned long);
	else if (len_modifier == LM_H)
		val = (unsigned short)va_arg(state->list, unsigned int);
	else if (len_modifier == LM_HH)
		val = (unsigned char)va_arg(state->list, unsigned int);
	else
		val = va_arg(state->list, unsigned int);
	
	return val;
}

long double read_real_val(struct ParserState *state, enum e_len_modifier len_modifier)
{
	long double val;
	
	val = 0;
	if (len_modifier == LM_CL)
		val = va_arg(state->list, long double);
	else
		val = va_arg(state->list, double);
	return val;
}


int print_uint(struct ParserState *state, int base, int uppercase, int always_ull, int undo_flags)
{
	t_fmt_pms params;
	unsigned long long val;
	params = read_format_params(state, base, uppercase);
	params.flags &= ~undo_flags;
	if (always_ull)
		params.len_modifier = LM_LL;
	val = read_uint_val(state, params.len_modifier);
	return print_val(&val, PT_UINT, &params);
}

int print_char(struct ParserState *state)
{
	t_fmt_pms params;
	char c;
	params = read_format_params(state, 10, 0);
	params.flags &= ~F_SPACE;
	c = (char)va_arg(state->list, int);
	return print_val(&c, PT_CHAR, &params);
}

int print_str(struct ParserState *state, char *val)
{
	t_fmt_pms params;
	params = read_format_params(state, 10, 0);
	if (val)
{
		params.flags &= ~F_SPACE;
		params.preci = -1;
	}

	else
		val = va_arg(state->list, char *);
	return print_val(val, PT_STR, &params);
}

int print_ptr(struct ParserState *state)
{
	t_fmt_pms params;
	unsigned long long val;
	void *ptr;
	params = read_format_params(state, 16, 0);
	params.flags |= F_DIEZ;
	params.len_modifier = LM_LL;
	ptr = va_arg(state->list, void *);
	val = (unsigned long long)ptr;
	return print_val(&val, PT_UINT, &params);
}

int print_real(struct ParserState *state)
{
	t_fmt_pms params;
	long double val;
	params = read_format_params(state, 10, 0);
	val = read_real_val(state, params.len_modifier);
	return print_val(&val, PT_REAL, &params);
}

int try_print_type(struct ParserState *state, const char *pos)
{
	int numPrinted = -1;
	if (*pos == 'd' || *pos == 'i')
		numPrinted = print_int(state);
	else if (*pos == 'c')
		numPrinted = print_char(state);
	else if (*pos == 's')
		numPrinted = print_str(state, 0);
	else if (*pos == '%')
		numPrinted = print_str(state, "%");
	else if (*pos == 'p')
		numPrinted = print_ptr(state);
	else if (*pos == 'f' || *pos == 'F')
		numPrinted = print_real(state);
	else if (*pos == 'o'|| *pos == 'O')
		numPrinted = print_uint(state, 8, 0, 0, 0);
	else if (*pos == 'x' || *pos == 'X')
		numPrinted = print_uint(state, 16, *pos == 'X', 0, 0);
	else if (*pos == 'b'|| *pos == 'B')
		numPrinted = print_uint(state, 2, 0, 0, 0);
	else if (*pos == 'u' || *pos == 'U')
		numPrinted = print_uint(state, 10, 0, *pos == 'U', F_SPACE);
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
	
	while (*state.fmt)
{
		if (*state.fmt == '%')
{
			++state.fmt;
			numPrinted += print_single_type(&state);
		}

 else
{
			write(1, state.fmt, 1);
			++numPrinted;
			++state.fmt;
		}

	}

	
	va_end(state.list);
	
	return numPrinted;
}

