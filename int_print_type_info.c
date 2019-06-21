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

static char	get_sign(long long val, t_fmt_pms *fmt_prm)
{
	if (val < 0)
	{
		return ('-');
	}
	return (fmt_prm->flags & F_PLUS ? '+' : 0);
}

static void	abs_ll_to_digits(char *digits, long long val, int preci)
{
	int i;
	long long d;

	i = 0;
	if (val == 0 && preci != 0)
	{
		digits[0] = '0';
		++i;
	}
	while (val)
	{
		d = val - (val / 10) * 10;
		d = d < 0 ? -d : d;
		digits[i] = d + '0';
		val /= 10;
		++i;
	}
	digits[i] = 0;
	reverse_str(digits);
}

struct pt_inf	create_intpti(void *val_ptr, t_fmt_pms *fmt_prm)
{
	struct pt_inf res;
	long long val;

	val = *(long long *)val_ptr;
	res.type = PT_INT;
	res.sign = get_sign(val, fmt_prm);
	res.val_str = ft_strnew(LONG_LONG_BITS);
	res.free_val_str = 1;
	abs_ll_to_digits(res.val_str, val, fmt_prm->preci);
	ft_strcpy(res.prfx, "");
	res.num_leading_zeros = 0;
	if (fmt_prm->preci > (int)ft_strlen(res.val_str))
	{
		res.num_leading_zeros = fmt_prm->preci - (int)ft_strlen(res.val_str);
	}
	res.leading_zeros_allowed = fmt_prm->preci < 0;
	return (res);
}
