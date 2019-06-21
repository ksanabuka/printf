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

int	print_type_info_chars_count(const struct pt_inf *info)
{
	int res;

	res = 0;
	res += info->sign ? 1 : 0;
	res += ft_strlen(info->prfx);
	res += info->num_leading_zeros;
	res += info->type == PT_CHAR ? 1 : ft_strlen(info->val_str);
	return (res);
}

int	print_type_info(const struct pt_inf *info)
{
	if (info->sign)
	{
		write(1, &info->sign, 1);
	}
	write(1, info->prfx, ft_strlen(info->prfx));
	print_repeated_char('0', info->num_leading_zeros);
	if (info->type == PT_CHAR && info->val_str[0] == 0)
	{
		write(1, "^@", 2);
	}
	else
	{
		write(1, info->val_str, ft_strlen(info->val_str));
	}
	return (print_type_info_chars_count(info));
}

static int	should_try_to_add_leading_space(const struct Formattedpt_inf *info,\
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

static void try_to_add_leading_space(struct Formattedpt_inf *info, t_fmt_pms *fmt_prm)
{
	if ((fmt_prm->flags & F_ZERO) && info->info->num_leading_zeros > 0)
	{
		--info->info->num_leading_zeros;
		++info->num_leading_spaces;
	}

	else if (!info->info->sign)
	{
		++info->num_leading_spaces;
	}
}

static int should_extend_width_by_using_zeros(struct pt_inf *info, t_fmt_pms *fmt_prm)
{
	return (fmt_prm->flags & F_ZERO) && (fmt_prm->flags & F_MINUS) == 0 && info->num_leading_zeros == 0 && info->leading_zeros_allowed;
}

struct Formattedpt_inf create_formattedpti(struct pt_inf *info, t_fmt_pms *fmt_prm)
{
	struct Formattedpt_inf res;
	int info_len;

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

int print_formatted_type_info(const struct Formattedpt_inf *info)
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

void cleanup_formattedpti(const struct Formattedpt_inf *info)
{
	if (info->info->free_val_str)
{
		free(info->info->val_str);
	}

}


void reverse_str(char *str)
{
	int len;
	int i;
	char c;

	len = (int)ft_strlen(str);
	i = 0;

	while (i + i < len)

{
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		++i;
	}

}

void print_repeated_char(char c, int num)
{
	int i;

	i = 0;
	while (i < num)

{
		write(1, &c, 1);
		++i;
	}

}
