/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_type_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:58:56 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:03 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_print_type_info.h"

char	*abs_integral_and_fractural_join(long double val, t_fmt_pms *fmt_prm)
{
	char *tmp;
	char *fracturial_part;
	char *integral_part;
	char *digits;

	digits = ft_strnew(64);
	val = (val < 0) ? -val : val;
	fracturial_part = fracture_part(&val, fmt_prm);
	integral_part = abs_integral_quotient_to_digits(digits, val);
	if (fracturial_part[0] != '\0' && fmt_prm->preci != 0)
	{
		tmp = ft_strnew(1);
		tmp[0] = '.';
		integral_part = digits;
		digits = ft_strjoin(digits, tmp);
		free(integral_part);
		free(tmp);
	}
	integral_part = digits;
	digits = ft_strjoin(digits, fracturial_part);
	free(integral_part);
	free(fracturial_part);
	return (digits);
}

t_pti	create_realpti(void *val_ptr, t_fmt_pms *fmt_prm)
{
	t_pti			res;
	long double		val;

	val = *(long double *)val_ptr;
	res.type = PT_REAL;
	res.sign = get_sign(val, fmt_prm);
	res.val_str = abs_integral_and_fractural_join(val, fmt_prm);
	res.free_val_str = 1;
	ft_strcpy(res.prfx, "");
	res.num_leading_zeros = 0;
	if (fmt_prm->flags & F_MINUS && fmt_prm->flags & F_ZERO)
	{
		res.leading_zeros_allowed = 0;
	}
	res.leading_zeros_allowed = 1;
	return (res);
}
