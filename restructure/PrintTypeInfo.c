//
//  PrintTypeInfo.c
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include "libft/libft.h"
#include "PrintTypeInfo.h"
#include <unistd.h>

int print_type_info_chars_count(const struct PrintTypeInfo *info) {
    int res;
    
    res = 0;
    res += info->sign ? 1 : 0;
    res += ft_strlen(info->prefix);
    res += info->num_leading_zeros;
    res += ft_strlen(info->value_str);
    return res;
}

int print_type_info(const struct PrintTypeInfo *info) {
    if (info->sign) {
        write(1, &info->sign, 1);
    }
    write(1, info->prefix, ft_strlen(info->prefix));
    print_repeated_char('0', info->num_leading_zeros);
    write(1, info->value_str, ft_strlen(info->value_str));
    
    return print_type_info_chars_count(info);
}

static int should_try_to_add_leading_space(const struct FormattedPrintTypeInfo *info, const struct FormatParams *fmt_params) {
    
     
    if  ((fmt_params->flags & F_SPACE) && info->info->sign != 0 && info->info->type == 'f') 
        return 0; 

    if ((fmt_params->flags & F_SPACE) && info->num_leading_spaces == 0 && (fmt_params->flags & F_MINUS) == 0)
        return 1;
    else 
        return 0; 

}

static void try_to_add_leading_space(struct FormattedPrintTypeInfo *info, const struct FormatParams *fmt_params) {
    if ((fmt_params->flags & F_ZERO) && info->info->num_leading_zeros > 0) {
        --info->info->num_leading_zeros;
        ++info->num_leading_spaces;
    } else if (!info->info->sign) {
        ++info->num_leading_spaces;
    }
}

static int should_extend_width_by_using_zeros(struct PrintTypeInfo *info, const struct FormatParams *fmt_params) {
    return (fmt_params->flags & F_ZERO) && (fmt_params->flags & F_MINUS) == 0 && info->num_leading_zeros == 0 && info->leading_zeros_allowed;
}

struct FormattedPrintTypeInfo create_formatted_print_type_info(struct PrintTypeInfo *info, const struct FormatParams *fmt_params) {
    struct FormattedPrintTypeInfo res;
    int info_len;
    
    res.num_leading_spaces = 0;
    res.info = info;
    res.num_trailing_spaces = 0;
    info_len = print_type_info_chars_count(info);
    
    if (info_len < fmt_params->width) {
        if (should_extend_width_by_using_zeros(info, fmt_params))
            info->num_leading_zeros = fmt_params->width - info_len;
        else if ((fmt_params->flags & F_MINUS) == 0)
            res.num_leading_spaces = fmt_params->width - info_len;
        else
            res.num_trailing_spaces = fmt_params->width - info_len;
    }
    
    if (should_try_to_add_leading_space(&res, fmt_params))
        try_to_add_leading_space(&res, fmt_params);
    
    return res;
}

int print_formatted_type_info(const struct FormattedPrintTypeInfo *info) {
    int res;
    
    res = 0;
    print_repeated_char(' ', info->num_leading_spaces);
    res += info->num_leading_spaces;
    res += print_type_info(info->info);
    print_repeated_char(' ', info->num_trailing_spaces);
    res += info->num_trailing_spaces;
    return res;
}

void cleanup_formatted_print_type_info(const struct FormattedPrintTypeInfo *info) {
    if (info->info->free_value_str) {
        free(info->info->value_str);
    }
}

// ----------------------------

void reverse_str(char *str)
{
    int len;
    int i;
    char c;
    
    len = (int)ft_strlen(str);
    i = 0;
    
    while (i + i < len)
    {
        c = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = c;
        ++i;
    }
}

void print_repeated_char(char c, int num) {
    int i;
    
    i = 0;
    while (i < num)
    {
        write(1, &c, 1);
        ++i;
    }
}
