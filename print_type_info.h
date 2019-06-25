/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_info.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:58:12 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:58:16 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TYPE_INFO_H
# define PRINT_TYPE_INFO_H

enum					e_flags
{
	F_PLUS = 1 << 0,
	F_MINUS = 1 << 1,
	F_ZERO = 1 << 2,
	F_SPACE = 1 << 3,
	F_DIEZ = 1 << 4,
    F_ALWAYS_PRINT_PREFIX = 1 << 5
};

enum					e_len_modifier
{
	LM_DEFAULT = 0,
	LM_HH = 1,
	LM_H = 2,
	LM_L = 3,
	LM_LL = 4,
	LM_CL = 5
};

typedef struct			s_fmt_pms
{
	int					flags;
	int					width;
    int                 width_wildcard;
	int					preci;
	enum e_len_modifier	len_modifier;
	int					int_base;
	int					is_prfx_uppercase;
}						t_fmt_pms;

enum					e_print_type
{
	PT_INT = 0,
	PT_UINT = 1,
	PT_STR = 2,
	PT_REAL = 3,
	PT_CHAR = 4
};

typedef struct			s_pt_inf
{
	enum e_print_type	type;
	char				sign;
	char				prfx[3];
	int					num_leading_zeros;
	char				*val_str;
	int					free_val_str;
	int					leading_zeros_allowed;
}						t_pti;

typedef struct			s_formatted_pti
{
	int					num_leading_spaces;
	t_pti				*info;
	int					num_trailing_spaces;
}						t_formatted_pti;

int						print_type_info_chars_count(const t_pti *info);
int						print_type_info(const t_pti *info);
t_formatted_pti			create_formatted_pti(t_pti *info, t_fmt_pms *fmt_prm);
int						print_formatted_type_info(const t_formatted_pti *info);
void					cleanup_formattedpti(const t_formatted_pti *info);
void					reverse_str(char *str);
void					print_repeated_char(char c, int num);
int						should_try_to_add_leading_space(const \
						t_formatted_pti *info, t_fmt_pms *fmt_prm);
void					try_to_add_leading_space(t_formatted_pti *info,\
						t_fmt_pms *fmt_prm);
int						should_extend_width_by_using_zeros(t_pti *info,\
						t_fmt_pms *fmt_prm);

#endif
