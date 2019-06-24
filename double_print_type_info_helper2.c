/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_type_info_helper2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:19:25 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 13:19:28 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_print_type_info.h"

char	*abs_integral_quotient_to_digits(char *digits, long double val)
{
	int			i;
	long long	integral_part;
	char		d;

	integral_part = (long long)val;
	if (integral_part == 0)
	{
		digits[0] = '0';
		return (digits);
	}
	i = 0;
	while (integral_part)
	{
		d = (integral_part - (integral_part / 10) * 10);
		d = d < 0 ? -d : d;
		digits[i] = d + '0';
		integral_part /= 10;
		++i;
	}
	digits[i] = 0;
	reverse_str(digits);
	return (digits);
}

void	helper_itoa(long double aftercoma, char *str, t_fmt_pms *fmt_prm)
{
	int i;

	i = 0;
	while (42)
	{
		if (fmt_prm->preci != -1 && i == fmt_prm->preci + 1)
			return ;
		if (aftercoma == 0 || (fmt_prm->preci == -1 && i == 7) || i == 17)
			return ;
		if ((int)(aftercoma * 10) == 0 && aftercoma != 0)
			str[i] = '0';
		else
			str[i] = (int)(aftercoma * 10) + '0';
		aftercoma = aftercoma * 10 - (int)(aftercoma * 10);
		i++;
	}
}

char	*he_adj_fract0(long double *val, t_fmt_pms *fmt_prm)
{
	*val = *val + 1;
	if (fmt_prm->preci == 0)
		return (ft_strnew(0));
	else if (fmt_prm->preci == -1)
		return (create_str_with_0(6));
	else if (fmt_prm->preci > 0)
		return (create_str_with_0(fmt_prm->preci));
	else
		return (0);
}
