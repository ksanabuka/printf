/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:58:04 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:58:10 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "double_print_type_info.h"
# include "int_print_type_info.h"
# include "string_print_type_info.h"
# include "uint_print_type_info.h"
# include "char_print_type_info.h"

typedef struct		s_parser_state
{
	const char		*fmt;
	va_list			list;
}					t_parser_state;

int					ft_printf(const char *fmt, ...);
int					print_single_type(t_parser_state *state);
int					try_print_type(t_parser_state *state, const char *pos);
int					print_val(void *val, enum e_print_type type,\
					t_fmt_pms *fmt_prm);
t_fmt_pms			read_format_params(t_parser_state *state,\
					int int_base, int is_prfx_uppercase);


int					read_flags(t_parser_state *state);
int					read_width_or_preci_val(t_parser_state *state);
int					read_width(t_parser_state *state);
int					read_preci(t_parser_state *state);
enum e_len_modifier	read_len_modifier(t_parser_state *state);


long long			read_int_val(t_parser_state *state,\
					enum e_len_modifier len_modifier);
unsigned long long	read_uint_val(t_parser_state *state,\
					enum e_len_modifier len_modifier);
long double			read_real_val(t_parser_state *state,\
					enum e_len_modifier len_modifier);
int					print_real(t_parser_state *state);


int					print_int(t_parser_state *state);
int					print_uint(t_parser_state *state, int base,
					int uppercase, int always_ull, int undo_flags);
int					print_char(t_parser_state *state);
int					print_str(t_parser_state *state, char *val);
int					print_ptr(t_parser_state *state);

#endif
