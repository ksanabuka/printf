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

#ifndef STRINGPRINTTYPEINFO_H
#define STRINGPRINTTYPEINFO_H
#include "PrintTypeInfo.h"
struct pt_inf create_strpti(void *str, const struct fmt_pms *fmt_params);
#endif
