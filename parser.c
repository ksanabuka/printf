/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:59:19 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/20 10:59:23 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"
#include "double_print_type_info.h"
#include "int_print_type_info.h"
#include "string_print_type_info.h"
#include "uint_print_type_info.h"
#include "char_print_type_info.h"
#include "parser.h"

int			print_val(void *val, enum e_print_type type, t_fmt_pms *fmt_prm)
{
	t_formatted_pti		formatted;
	t_pti				info;
	int					res;

	if (type == PT_INT)
		info = create_intpti(val, fmt_prm);
	else if (type == PT_UINT)
		info = create_uintpti(val, fmt_prm);
	else if (type == PT_STR)
		info = create_strpti(val, fmt_prm);
	else if (type == PT_REAL)
		info = create_realpti(val, fmt_prm);
	else if (type == PT_CHAR)
		info = create_charpti(val, fmt_prm);
	else
		return (0);
	formatted = create_formatted_pti(&info, fmt_prm);
	res = print_formatted_type_info(&formatted);
	cleanup_formattedpti(&formatted);
	return (res);
}

t_fmt_pms	read_format_params(t_parser_state *state,\
					int int_base, int is_prfx_uppercase)
{
	t_fmt_pms res;

	res.flags = read_flags(state);
	res.width = read_width(state);
	res.preci = read_preci(state);
	res.len_modifier = read_len_modifier(state);
	res.int_base = int_base;
	res.is_prfx_uppercase = is_prfx_uppercase;
	return (res);
}

int			try_print_type(t_parser_state *state, const char *pos)
{
	int num_printed;

	num_printed = -1;
	if (*pos == 'd' || *pos == 'i')
		num_printed = print_int(state);
	else if (*pos == 'c')
		num_printed = print_char(state);
	else if (*pos == 's')
		num_printed = print_str(state, 0);
	else if (*pos == '%')
		num_printed = print_str(state, "%");
	else if (*pos == 'p')
		num_printed = print_ptr(state);
	else if (*pos == 'f' || *pos == 'F')
		num_printed = print_real(state);
	else if (*pos == 'o' || *pos == 'O')
		num_printed = print_uint(state, 8, 0, 0, 0);
	else if (*pos == 'x' || *pos == 'X')
		num_printed = print_uint(state, 16, *pos == 'X', 0, 0);
	else if (*pos == 'b' || *pos == 'B')
		num_printed = print_uint(state, 2, 0, 0, 0);
	else if (*pos == 'u' || *pos == 'U')
		num_printed = print_uint(state, 10, 0, *pos == 'U', F_SPACE);
	return (num_printed);
}

int			print_single_type(t_parser_state *state)
{
	const char	*pos;
	int			num_printed;

	pos = state->fmt;
	num_printed = -1;
	while (*pos && num_printed < 0)
	{
		num_printed = try_print_type(state, pos);
		++pos;
	}
	if (num_printed >= 0)
		state->fmt = pos;
	else
	{
		num_printed = 0;
		while (*state->fmt)
		{
			write(1, state->fmt, 1);
			++state->fmt;
			++num_printed;
		}
	}
	return (num_printed);
}

int			ft_printf(const char *fmt, ...)
{
	t_parser_state		state;
	int					num_printed;

	state.fmt = fmt;
	num_printed = 0;
	va_start(state.list, fmt);
	while (*state.fmt)
	{
		if (*state.fmt == '%')
		{
			++state.fmt;
			num_printed += print_single_type(&state);
		}
		else
		{
			write(1, state.fmt, 1);
			++num_printed;
			++state.fmt;
		}
	}
	va_end(state.list);
	return (num_printed);
}
