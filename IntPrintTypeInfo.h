/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntPrintTypeInfo.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:49:59 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:50:04 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTPRINTTYPEINFO_H
#define INTPRINTTYPEINFO_H
#include "PrintTypeInfo.h"
struct pt_inf create_intpti(void *value_ptr, const struct fmt_pms *fmt_params);
#endif
