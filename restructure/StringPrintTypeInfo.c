//
//  StringPrintTypeInfo.c
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#include "StringPrintTypeInfo.h"
#include "libft.h"

struct PrintTypeInfo create_str_print_type_info(void *str, const struct FormatParams *fmt_params) {
    struct PrintTypeInfo res;
    
    res.sign = 0;
    res.prefix[0] = 0;
    res.num_leading_zeros = 0;
    res.value_str = (char *)str;
    res.free_value_str = 0;
    res.leading_zeros_allowed = 0;
    return res;
}
