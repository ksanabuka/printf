/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_type_info_helper1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:19:18 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 13:19:23 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_print_type_info.h"

static int	helper_trying_to_add_1_to_grade(char *s, int i)
{
	while (i >= 0)
	{
		if (s[i] < '9')
		{
			s[i] = s[i] + 1;
			return (1);
		}
		else
		{
			s[i] = '0';
			if (i == 0 && s[i] == '0')
				return (0);
			i--;
		}
	}
	return (0);
}

static int	rounding_five_nine(char *s, int i)
{
	if (s[i] >= '5' && s[i] <= '9' && i - 1 >= 0)
	{
		if (s[i - 1] < '9')
			s[i - 1] = s[i - 1] + 1;
		else
		{
			s[i - 1] = '0';
			i = i - 2;
			if (!helper_trying_to_add_1_to_grade(s, i))
				return (0);
		}
	}
	return (1);
}

char		*rounding(char *s)
{
	int		len;
	int		i;
	char	*new;

	if (s[0] == '\0')
		return (s);
	len = ft_strlen(s);
	i = len - 1;
	if (!rounding_five_nine(s, i))
		return (0);
	new = ft_strnew(len - 1);
	i = 0;
	while (i < len - 1)
	{
		new[i] = s[i];
		i++;
	}
	free(s);
	return (new);
}

char		*create_str_with_0(int len)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}
