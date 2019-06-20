/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print_type_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:36 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:41 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_print_type_info.h"
#include "libft.h"

struct  pt_inf	create_strpti(void *val, const t_fmt_pms *fmt_prm)
{
	char *str;
	int l;
	struct pt_inf res;

	str = val ? (char *)val : "(null)";
	l = (int)ft_strlen(str);
	res.type = PT_STR;
	res.sign = 0;
	res.prefix[0] = 0;
	res.num_leading_zeros = 0;
	if (fmt_prm->precision >= 0 && fmt_prm->precision < l)
	{
		res.value_str = ft_strnew(fmt_prm->precision);
		ft_strncpy(res.value_str, str, fmt_prm->precision);
		res.free_value_str = 1;
	}
	else
	{
		res.value_str = str;
		res.free_value_str = 0;
	}
	res.leading_zeros_allowed = 0;
	return (res);
}


