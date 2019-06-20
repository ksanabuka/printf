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

#ifndef CHARPRINTTYPEINFO_H
#define CHARPRINTTYPEINFO_H
#include "PrintTypeInfo.h"
struct pt_inf create_charpti(void *str, const struct fmt_pms *fmt_params);
#endif
