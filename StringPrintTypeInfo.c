/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringPrintTypeInfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:48:14 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:48:21 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringPrintTypeInfo.h"
#include "libft.h"
struct pt_inf create_strpti(void *val, const struct fmt_pms *fmt_params)
{
    char *str;
    int l;
    struct pt_inf res;
    
    str = val ? (char *)val : "(null)";
    l = (int)ft_strlen(str);
    
    res.type = PT_STR;
    res.sign = 0;
    res.prefix[0] = 0;
    res.num_leading_zeros = 0;
    
    if (fmt_params->precision >= 0 && fmt_params->precision < l)
{
        res.value_str = ft_strnew(fmt_params->precision);
        ft_strncpy(res.value_str, str, fmt_params->precision);
        res.free_value_str = 1;
    }

 else
{
        res.value_str = str;
        res.free_value_str = 0;
    }


    res.leading_zeros_allowed = 0;
    return res;
}


