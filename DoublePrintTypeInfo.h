/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoublePrintTypeInfo.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:49:54 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:49:57 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DoublePrintTypeInfo_h
#define DoublePrintTypeInfo_h
#include "PrintTypeInfo.h"
struct PrintTypeInfo create_real_print_type_info(void *value_ptr, const struct FormatParams *fmt_params); 

#endif
