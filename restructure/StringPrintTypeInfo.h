//
//  StringPrintTypeInfo.h
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#ifndef StringPrintTypeInfo_h
#define StringPrintTypeInfo_h

#include "PrintTypeInfo.h"

struct PrintTypeInfo create_str_print_type_info(void *str, const struct FormatParams *fmt_params);

#endif /* StringPrintTypeInfo_h */
