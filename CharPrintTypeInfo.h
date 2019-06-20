//
//  CharPrintTypeInfo.h
//  printf
//
//  Created by Oksana Buksha on 6/12/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//

#ifndef CharPrintTypeInfo_H
#define CharPrintTypeInfo_H

#include "PrintTypeInfo.h"

struct PrintTypeInfo create_char_print_type_info(void *str, const struct FormatParams *fmt_params);

#endif /* CharPrintTypeInfo_H */
