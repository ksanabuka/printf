/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print_type_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:44 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:48 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "uint_print_type_info.h"
#define UNSIGNED_LONG_LONG_BITS (8 * sizeof(unsigned long long))

static void set_num_prefix(char prefix[3], unsigned long long value, const struct fmt_pms *fmt_params)
{
    ft_strcpy(prefix, "");

    if (fmt_params->flags & F_DIEZ)
{
        if (fmt_params->int_base == 2 && value)
{
            ft_strcpy(prefix, fmt_params->is_prefix_uppercase ? "0B" : "0b");
        }
else if (fmt_params->int_base == 8 && (value != 0 || fmt_params->precision >= 0))
{
            ft_strcpy(prefix, "0");
        }
else if (fmt_params->int_base == 16 && value)
{
            ft_strcpy(prefix, fmt_params->is_prefix_uppercase ? "0X" : "0x");
        }
    }
}
static void ull_to_digits(char *digits, unsigned long long value, const struct fmt_pms *fmt_params)
{
    int i;
    unsigned long long d;

    i = 0;
    if (value == 0 && fmt_params->precision != 0)

{
        digits[0] = '0';
        ++i;
    }
    while (value)

{
        d = value - (value / fmt_params->int_base) * fmt_params->int_base;
        digits[i] = d < 10 ? d + '0' : d - 10 + (fmt_params->is_prefix_uppercase ? 'A' : 'a');
        value /= fmt_params->int_base;
        ++i;
    }
    digits[i] = 0;
    reverse_str(digits);
}
struct pt_inf create_uintpti(void *value_ptr, const struct fmt_pms *fmt_params)
{
    struct pt_inf res;
    int num_extra_zeros;
    unsigned long long value;

    value = *(unsigned long long *)value_ptr;
    res.type = PT_UINT;
    res.sign = 0;
    res.value_str = ft_strnew(UNSIGNED_LONG_LONG_BITS);
    res.free_value_str = 1;
    ull_to_digits(res.value_str, value, fmt_params);
    set_num_prefix(res.prefix, value, fmt_params);
    res.num_leading_zeros = 0;
    num_extra_zeros = fmt_params->int_base == 8 && res.prefix[0] == '0' ? 1 : 0;
    if (fmt_params->precision > num_extra_zeros + (int)ft_strlen(res.value_str))
{
        res.num_leading_zeros = fmt_params->precision - num_extra_zeros - (int)ft_strlen(res.value_str);
    }
    res.leading_zeros_allowed = fmt_params->precision < 0;
    return res;
}
