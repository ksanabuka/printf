//
//  StringPrintTypeInfo.c
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include "StringPrintTypeInfo.h"
#include "libft.h"

struct PrintTypeInfo create_str_print_type_info(void *val, const struct FormatParams *fmt_params) {
    char *str;
    int l;
    struct PrintTypeInfo res;
    
    str = val ? (char *)val : "(null)";
    l = (int)ft_strlen(str);
    
    res.type = PT_STR;
    res.sign = 0;
    res.prefix[0] = 0;
    res.num_leading_zeros = 0;
    
    if (fmt_params->precision >= 0 && fmt_params->precision < l) {
        res.value_str = ft_strnew(fmt_params->precision);
        ft_strncpy(res.value_str, str, fmt_params->precision);
        res.free_value_str = 1;
    } else {
        res.value_str = str;
        res.free_value_str = 0;
    }

    res.leading_zeros_allowed = 0;
    return res;
}
