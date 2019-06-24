/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_type_info.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:57:37 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:57:45 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_PRINT_TYPE_INFO_H
# define DOUBLE_PRINT_TYPE_INFO_H
# include "print_type_info.h"
# include "libft.h"



char	*create_str_with_0(int len);
char	*rounding(char *s);

void	helper_itoa(long double aftercoma, char *str, t_fmt_pms *fmt_prm);
char	*he_adj_fract0(long double *val, t_fmt_pms *fmt_prm);
char	*abs_integral_quotient_to_digits(char *digits, long double val);

char	*fracture_part(long double *val, t_fmt_pms *fmt_prm);
char	get_sign(long double val, t_fmt_pms *fmt_prm);


char	*abs_integral_and_fractural_join(long double val, t_fmt_pms *fmt_prm);
t_pti	create_realpti(void *val_ptr, t_fmt_pms *fmt_prm);


#endif
