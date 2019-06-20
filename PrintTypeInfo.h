/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintTypeInfo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 08:50:11 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 08:50:14 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PrintTypeInfo_h
#define PrintTypeInfo_h
enum Flags
{
    F_PLUS = 1 << 0,
    F_MINUS = 1 << 1,
    F_ZERO = 1 << 2,
    F_SPACE = 1 << 3,
    F_DIEZ = 1 << 4
};

enum LenModifier
{
    LM_DEFAULT = 0,
    LM_HH = 1,
    LM_H = 2,
    LM_L = 3,
    LM_LL = 4,
    LM_CL = 5
};

struct FormatParams
{
    int flags;
    int width;
    int precision;
    enum LenModifier lenModifier;
    int int_base;
    int is_prefix_uppercase;
};

enum PrintType
{
    PT_INT = 0,
    PT_UINT = 1,
    PT_STR = 2,
    PT_REAL = 3,
    PT_CHAR = 4
};

struct PrintTypeInfo
{
    enum PrintType type;
    char sign;
    char prefix[3];
    int num_leading_zeros;
    char *value_str;
    int free_value_str;
    int leading_zeros_allowed;
};
int print_type_info_chars_count(const struct PrintTypeInfo *info);
int print_type_info(const struct PrintTypeInfo *info);
struct FormattedPrintTypeInfo
{
    int num_leading_spaces;
    struct PrintTypeInfo *info;
    int num_trailing_spaces;
}

;
struct FormattedPrintTypeInfo create_formatted_print_type_info(struct PrintTypeInfo *info, const struct FormatParams *fmt_params);
int print_formatted_type_info(const struct FormattedPrintTypeInfo *info);
void cleanup_formatted_print_type_info(const struct FormattedPrintTypeInfo *info);
void reverse_str(char *str);
void print_repeated_char(char c, int num);
#endif
