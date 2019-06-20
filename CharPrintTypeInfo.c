/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharPrintTypeInfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:46:17 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:49:25 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CharPrintTypeInfo.h"
#include "libft.h"
struct pt_inf create_charpti(void *val, const struct fmt_pms *fmt_params)
{
    struct pt_inf res;
    fmt_params = 0;
    res.type = PT_CHAR;
    res.sign = 0;
    res.prefix[0] = 0;
    res.num_leading_zeros = 0;
    res.value_str = ft_strnew(1);
    res.value_str[0] = *(char *)val;
    res.free_value_str = 1;
    res.leading_zeros_allowed = 0;
    return res;
}


