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

struct pt_inf	create_charpti(void *val, t_fmt_pms *fmt_prm)
{
	struct pt_inf res;

	fmt_prm = 0;
	res.type = PT_CHAR;
	res.sign = 0;
	res.prfx[0] = 0;
	res.num_leading_zeros = 0;
	res.val_str = ft_strnew(1);
	res.val_str[0] = *(char *)val;
	res.free_val_str = 1;
	res.leading_zeros_allowed = 0;
	return (res);
}
