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

int			try_print_type(t_parser_state *state, const char *pos, t_fmt_pms *fmt)
{
	int num_printed;

	num_printed = -1;
	if (*pos == 'd' || *pos == 'i')
		num_printed = print_int(state, fmt);
	else if (*pos == 'c')
		num_printed = print_char(state, fmt);
	else if (*pos == 's')
		num_printed = print_str(state, 0, fmt);
	else if (*pos == '%')
		num_printed = print_str(state, "%", fmt);
	else if (*pos == 'p')
		num_printed = print_ptr(state, fmt);
	else if (*pos == 'f' || *pos == 'F')
		num_printed = print_real(state, fmt);
    else if (*pos == 'o' || *pos == 'O' || *pos == 'x' || *pos == 'X' || *pos == 'b' || *pos == 'B' || *pos == 'u' || *pos == 'U')
		num_printed = print_uint(state, fmt, *pos);
	return (num_printed);
}

int			print_single_type(t_parser_state *state)
{
    int         num_printed;
	const char	*pos;
    t_fmt_pms   fmt;
    
    fmt = init_fmt_params();
	pos = state->fmt;
	num_printed = -1;
	while (*pos && num_printed < 0)
	{
        if (!update_fmt(state, &fmt, *pos))
        {
            num_printed = try_print_type(state, pos, &fmt);
            if (num_printed < 0)
            {
                write(1, pos, 1);
                num_printed = 1;
            }
        }
		++pos;
	}
    state->fmt = pos;
    return (num_printed);
}

int			ft_printf(const char *fmt, ...)
{
	t_parser_state		state;
	int					num_printed;
    int                 num_printed_single;

	state.fmt = fmt;
	num_printed = 0;
	va_start(state.list, fmt);
	while (*state.fmt)
	{
		if (*state.fmt == '%')
		{
			++state.fmt;
            num_printed_single = print_single_type(&state);
            if (num_printed_single >= 0)
                num_printed += num_printed_single;
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
