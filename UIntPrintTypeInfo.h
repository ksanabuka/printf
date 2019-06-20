/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIntPrintTypeInfo.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:50:22 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:50:25 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UIntPrintTypeInfo_h
#define UIntPrintTypeInfo_h
#include "PrintTypeInfo.h"
struct PrintTypeInfo create_uint_print_type_info(void *value_ptr, const struct FormatParams *fmt_params);
#endif
