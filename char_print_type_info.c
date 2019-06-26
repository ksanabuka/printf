/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print_type_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:58:51 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:58:54 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_print_type_info.h"
#include "libft.h"

t_pti	create_charpti(void *val, t_fmt_pms *fmt_prm)
{
	t_pti	res;
	char	c;

	c = *(char *)val;
	res.type = PT_CHAR;
	res.sign = 0;
	if (c == 0 && fmt_prm->preci != 0)
		ft_strcpy(res.prfx, "^@");
	else
		ft_strcpy(res.prfx, "");
	res.num_leading_zeros = 0;
	res.val_str = ft_strnew(1);
	res.val_str[0] = c;
	res.free_val_str = 1;
	res.leading_zeros_allowed = 1;
	return (res);
}
