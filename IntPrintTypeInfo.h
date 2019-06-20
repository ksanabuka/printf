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

#ifndef IntPrintTypeInfo_h
#define IntPrintTypeInfo_h
#include "PrintTypeInfo.h"
struct PrintTypeInfo create_int_print_type_info(void *value_ptr, const struct FormatParams *fmt_params);
#endif
