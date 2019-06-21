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

t_pti	create_strpti(void *val, t_fmt_pms *fmt_prm)
{
	char *str;
	int l;
	t_pti res;

	str = val ? (char *)val : "(null)";
	l = (int)ft_strlen(str);
	res.type = PT_STR;
	res.sign = 0;
	res.prfx[0] = 0;
	res.num_leading_zeros = 0;
	if (fmt_prm->preci >= 0 && fmt_prm->preci < l)
	{
		res.val_str = ft_strnew(fmt_prm->preci);
		ft_strncpy(res.val_str, str, fmt_prm->preci);
		res.free_val_str = 1;
	}
	else
	{
		res.val_str = str;
		res.free_val_str = 0;
	}
	res.leading_zeros_allowed = 0;
	return (res);
}

