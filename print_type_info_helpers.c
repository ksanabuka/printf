/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_info_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:46:49 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 09:47:01 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_type_info.h"
#include "libft.h"

void	try_to_add_leading_space(t_formatted_pti *info, t_fmt_pms *fmt_prm)
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

int		should_extend_width_by_using_zeros(t_pti *info, t_fmt_pms *fmt_prm)
{
	return ((fmt_prm->flags & F_ZERO) && (fmt_prm->flags & F_MINUS) == 0 \
			&& info->num_leading_zeros == 0 && info->leading_zeros_allowed);
}

void	cleanup_formattedpti(const t_formatted_pti *info)
{
	if (info->info->free_val_str)
	{
		free(info->info->val_str);
	}
}

void	reverse_str(char *str)
{
	int		len;
	int		i;
	char	c;

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

void	print_repeated_char(char c, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		write(1, &c, 1);
		++i;
	}
}
