/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_type_info_helper3.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:19:30 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 13:19:33 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_print_type_info.h"

char		get_sign(long double val, t_fmt_pms *fmt_prm)
{
	if (val < 0)
	{
		return ('-');
	}
	return (fmt_prm->flags & F_PLUS ? '+' : 0);
}

static char	*handling_preci(char *str, t_fmt_pms *fmt_prm)
{
	int		len1;
	char	*tmp;
	char	*res;

	len1 = fmt_prm->preci - (int)ft_strlen(str);
	tmp = create_str_with_0(len1);
	res = str;
	str = ft_strjoin(str, tmp);
	free(res);
	free(tmp);
	return (str);
}

static char	*handling_diez(char *str)
{
	int		len;
	char	*tmp;
	char	*res;
	int		i;

	len = 6 - ft_strlen(str);
	tmp = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		tmp[i] = '0';
		i++;
	}
	res = str;
	str = ft_strjoin(str, tmp);
	free(res);
	free(tmp);
	return (str);
}

char		*fracture_part(long double *val, t_fmt_pms *fmt_prm)
{
	char		*str;
	long double	aftercoma;

	if (fmt_prm->preci == 0)
	{
		str = ft_strnew(0);
		return (str);
	}
	str = ft_strnew(17);
	aftercoma = *val - (long long)(*val);
	helper_itoa(aftercoma, str, fmt_prm);
	str = rounding(str);
	if (!str)
		str = he_adj_fract0(val, fmt_prm);
	else if (str[0] == '\0')
	{
		*val = *val - 1;
		str = he_adj_fract0(val, fmt_prm);
	}
	if (fmt_prm->preci > 0 && (int)ft_strlen(str) < fmt_prm->preci)
		str = handling_preci(str, fmt_prm);
	if (ft_strlen(str) < 6 && fmt_prm->flags & F_DIEZ)
		str = handling_diez(str);
	return (str);
}
