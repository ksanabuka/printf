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

static void		set_num_prfx(char prfx[3], unsigned long long v,\
				t_fmt_pms *fmt_prm)
{
	ft_strcpy(prfx, "");
	if (fmt_prm->flags & F_DIEZ)
	{
		if (fmt_prm->int_base == 2 && v)
		{
			ft_strcpy(prfx, fmt_prm->is_prfx_uppercase ? "0B" : "0b");
		}
		else if (fmt_prm->int_base == 8 && (v != 0 || fmt_prm->preci >= 0))
		{
			ft_strcpy(prfx, "0");
		}
		else if (fmt_prm->int_base == 16 && v)
		{
			ft_strcpy(prfx, fmt_prm->is_prfx_uppercase ? "0X" : "0x");
		}
	}
}

static void		ull_to_digits(char *digs, unsigned long long v,\
				t_fmt_pms *fmt_prm)
{
	int					i;
	unsigned long long	d;

	i = 0;
	if (v == 0 && fmt_prm->preci != 0)
	{
		digs[0] = '0';
		++i;
	}
	while (v)
	{
		d = v - (v / fmt_prm->int_base) * fmt_prm->int_base;
		if (d < 10)
			digs[i] = d + '0';
		else
			digs[i] = d - 10 + ((fmt_prm->is_prfx_uppercase) ? 'A' : 'a');
		v /= fmt_prm->int_base;
		++i;
	}
	digs[i] = 0;
	reverse_str(digs);
}

t_pti			create_uintpti(void *val_ptr, t_fmt_pms *fmt_prm)
{
	t_pti				res;
	int					num_extra_zeros;
	unsigned long long	val;
	int					len;

	val = *(unsigned long long *)val_ptr;
	res.type = PT_UINT;
	res.sign = 0;
	res.val_str = ft_strnew(UNSIGNED_LONG_LONG_BITS);
	res.free_val_str = 1;
	ull_to_digits(res.val_str, val, fmt_prm);
	set_num_prfx(res.prfx, val, fmt_prm);
	res.num_leading_zeros = 0;
	num_extra_zeros = fmt_prm->int_base == 8 && res.prfx[0] == '0' ? 1 : 0;
	if (fmt_prm->preci > num_extra_zeros + (int)ft_strlen(res.val_str))
	{
		len = (int)ft_strlen(res.val_str);
		res.num_leading_zeros = fmt_prm->preci - num_extra_zeros - len;
	}
	res.leading_zeros_allowed = fmt_prm->preci < 0;
	return (res);
}
