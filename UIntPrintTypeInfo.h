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

#ifndef UINTPRINTTYPEINFO_H
#define UINTPRINTTYPEINFO_H
#include "PrintTypeInfo.h"
struct pt_inf create_uintpti(void *value_ptr, const struct fmt_pms *fmt_params);
#endif
