/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:26 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:30 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_type_info.h"
#include "libft.h"

int				print_type_info_chars_count(const t_pti *info)
{
	int res;

	res = 0;
	res += info->sign ? 1 : 0;
	if (info->type == PT_CHAR)
		res += info->prfx[0] ? 1 : 0;
	else
		res += ft_strlen(info->prfx);
	res += info->num_leading_zeros;
	res += ft_strlen(info->val_str);
	return (res);
}

int				should_try_to_add_leading_space(const t_formatted_pti *info,\
											t_fmt_pms *fmt_prm)
{
	if ((fmt_prm->flags & F_SPACE) && info->info->sign != 0 \
		&& info->info->type == PT_REAL)
		return (0);
	if ((fmt_prm->flags & F_SPACE) && info->num_leading_spaces == 0 && \
		(fmt_prm->flags & F_MINUS) == 0)
		return (1);
	else
		return (0);
}

int				print_type_info(const t_pti *info)
{
	if (info->sign)
	{
		write(1, &info->sign, 1);
	}
	write(1, info->prfx, ft_strlen(info->prfx));
	print_repeated_char('0', info->num_leading_zeros);
	write(1, info->val_str, ft_strlen(info->val_str));
	return (print_type_info_chars_count(info));
}

t_formatted_pti	create_formatted_pti(t_pti *info, t_fmt_pms *fmt_prm)
{
	t_formatted_pti	res;
	int				info_len;

	res.num_leading_spaces = 0;
	res.info = info;
	res.num_trailing_spaces = 0;
	info_len = print_type_info_chars_count(info);
	if (info_len < fmt_prm->width)
	{
		if (should_extend_width_by_using_zeros(info, fmt_prm))
			info->num_leading_zeros = fmt_prm->width - info_len;
		else if ((fmt_prm->flags & F_MINUS) == 0)
			res.num_leading_spaces = fmt_prm->width - info_len;
		else
			res.num_trailing_spaces = fmt_prm->width - info_len;
	}
	if (should_try_to_add_leading_space(&res, fmt_prm))
		try_to_add_leading_space(&res, fmt_prm);
	return (res);
}

int				print_formatted_type_info(const t_formatted_pti *info)
{
	int res;

	res = 0;
	print_repeated_char(' ', info->num_leading_spaces);
	res += info->num_leading_spaces;
	res += print_type_info(info->info);
	print_repeated_char(' ', info->num_trailing_spaces);
	res += info->num_trailing_spaces;
	return (res);
}
