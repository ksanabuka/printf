/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print_type_info.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:58:18 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:58:23 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_PRINT_TYPE_INFO_H
# define STRING_PRINT_TYPE_INFO_H
# include "print_type_info.h"

struct pt_inf create_strpti(void *str, const struct fmt_pms *fmt_params);

#endif
