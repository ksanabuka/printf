//
//  CharPrintTypeInfo.c
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include "CharPrintTypeInfo.h"
#include "libft.h"

struct PrintTypeInfo create_char_print_type_info(void *val, const struct FormatParams *fmt_params) {
    struct PrintTypeInfo res;
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
