/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharPrintTypeInfo.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:49:42 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:49:52 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CharPrintTypeInfo_H
#define CharPrintTypeInfo_H
#include "PrintTypeInfo.h"
struct PrintTypeInfo create_char_print_type_info(void *str, const struct FormatParams *fmt_params);
#endif
