//
//  IntPrintTypeInfo.h
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#ifndef IntPrintTypeInfo_h
#define IntPrintTypeInfo_h

#include "PrintTypeInfo.h"

struct PrintTypeInfo create_int_print_type_info(void *value_ptr, const struct FormatParams *fmt_params);

#endif /* IntPrintTypeInfo_h */
