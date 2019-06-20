/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print_type_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:06 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:10 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "int_print_type_info.h"
#define LONG_LONG_BITS (8 * sizeof(long long))
static char get_sign(long long value, const t_fmt_pms *fmt_prm)
{
    if (value < 0)
{
        return '-';
    }


    return fmt_prm->flags & F_PLUS ? '+' : 0;
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


struct pt_inf create_intpti(void *value_ptr, const t_fmt_pms *fmt_prm)
{
    struct pt_inf res;
    long long value;

    value = *(long long *)value_ptr;
    res.type = PT_INT;
    res.sign = get_sign(value, fmt_prm);
    res.value_str = ft_strnew(LONG_LONG_BITS);
    res.free_value_str = 1;
    abs_ll_to_digits(res.value_str, value, fmt_prm->precision);
    ft_strcpy(res.prefix, "");
    res.num_leading_zeros = 0;
    if (fmt_prm->precision > (int)ft_strlen(res.value_str))
{
        res.num_leading_zeros = fmt_prm->precision - (int)ft_strlen(res.value_str);
    }


    res.leading_zeros_allowed = fmt_prm->precision < 0;
    return res;
}


