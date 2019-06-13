//
//  UIntPrintTypeInfo.h
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#ifndef UIntPrintTypeInfo_h
#define UIntPrintTypeInfo_h

#include "PrintTypeInfo.h"

struct PrintTypeInfo create_uint_print_type_info(void *value_ptr, const struct FormatParams *fmt_params);

#endif /* UIntPrintTypeInfo_h */
