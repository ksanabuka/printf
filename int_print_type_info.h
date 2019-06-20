/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print_type_info.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:57:57 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:58:01 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_PRINT_TYPE_INFO_H
# define INT_PRINT_TYPE_INFO_H
# include "print_type_info.h"

struct pt_inf create_intpti(void *value_ptr, const struct fmt_pms *fmt_params);

#endif
