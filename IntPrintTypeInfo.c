/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntPrintTypeInfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:48:51 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:48:53 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "IntPrintTypeInfo.h"
#define LONG_LONG_BITS (8 * sizeof(long long))
static char get_sign(long long value, const struct FormatParams *fmt_params)
{
    if (value < 0)
{
        return '-';
    }


    return fmt_params->flags & F_PLUS ? '+' : 0;
}


static void abs_ll_to_digits(char *digits, long long value, int precision)
{
    int i;
    long long d;
    
    i = 0;
    if (value == 0 && precision != 0)
   
{
        digits[0] = '0';
        ++i;
    }


    while (value)
   
{
        d = value - (value / 10) * 10;
        d = d < 0 ? -d : d;
        digits[i] = d + '0';
        value /= 10;
        ++i;
    }


    digits[i] = 0;
    reverse_str(digits);
}


struct PrintTypeInfo create_int_print_type_info(void *value_ptr, const struct FormatParams *fmt_params)
{
    struct PrintTypeInfo res;
    long long value;
    
    value = *(long long *)value_ptr;
    res.type = PT_INT;
    res.sign = get_sign(value, fmt_params);
    res.value_str = ft_strnew(LONG_LONG_BITS);
    res.free_value_str = 1;
    abs_ll_to_digits(res.value_str, value, fmt_params->precision);
    ft_strcpy(res.prefix, "");
    res.num_leading_zeros = 0;
    if (fmt_params->precision > (int)ft_strlen(res.value_str))
{
        res.num_leading_zeros = fmt_params->precision - (int)ft_strlen(res.value_str);
    }


    res.leading_zeros_allowed = fmt_params->precision < 0;
    return res;
}


