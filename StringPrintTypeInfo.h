/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringPrintTypeInfo.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:50:16 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:50:19 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef StringPrintTypeInfo_h
#define StringPrintTypeInfo_h
#include "PrintTypeInfo.h"
struct PrintTypeInfo create_str_print_type_info(void *str, const struct FormatParams *fmt_params);
#endif
