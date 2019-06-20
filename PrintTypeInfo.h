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

#ifndef PRINTTYPEINFO_H
#define PRINTTYPEINFO_H
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

struct fmt_pms
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

struct pt_inf
{
    enum PrintType type;
    char sign;
    char prefix[3];
    int num_leading_zeros;
    char *value_str;
    int free_value_str;
    int leading_zeros_allowed;
};
int print_type_info_chars_count(const struct pt_inf *info);
int print_type_info(const struct pt_inf *info);
struct Formattedpt_inf
{
    int num_leading_spaces;
    struct pt_inf *info;
    int num_trailing_spaces;
}

;
struct Formattedpt_inf create_formattedpti(struct pt_inf *info, const struct fmt_pms *fmt_params);
int print_formatted_type_info(const struct Formattedpt_inf *info);
void cleanup_formattedpti(const struct Formattedpt_inf *info);
void reverse_str(char *str);
void print_repeated_char(char c, int num);
#endif
