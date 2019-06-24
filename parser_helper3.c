/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:54:20 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 09:54:26 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	print_int(t_parser_state *state)
{
	t_fmt_pms params;
	long long val;

	params = read_format_params(state, 10, 0);
	val = read_int_val(state, params.len_modifier);
	return (print_val(&val, PT_INT, &params));
}

int	print_uint(t_parser_state *state, int base,
				int uppercase, int always_ull, int undo_flags)
{
	t_fmt_pms			params;
	unsigned long long	val;

	params = read_format_params(state, base, uppercase);
	params.flags &= ~undo_flags;
	if (always_ull)
		params.len_modifier = LM_LL;
	val = read_uint_val(state, params.len_modifier);
	return (print_val(&val, PT_UINT, &params));
}

int	print_char(t_parser_state *state)
{
	t_fmt_pms	params;
	char		c;

	params = read_format_params(state, 10, 0);
	params.flags &= ~F_SPACE;
	c = (char)va_arg(state->list, int);
	return (print_val(&c, PT_CHAR, &params));
}

int	print_str(t_parser_state *state, char *val)
{
	t_fmt_pms params;

	params = read_format_params(state, 10, 0);
	if (val)
	{
		params.flags &= ~F_SPACE;
		params.preci = -1;
	}
	else
		val = va_arg(state->list, char *);
	return (print_val(val, PT_STR, &params));
}

int	print_ptr(t_parser_state *state)
{
	t_fmt_pms			params;
	unsigned long long	val;
	void				*ptr;

	params = read_format_params(state, 16, 0);
	params.flags |= F_DIEZ;
	params.len_modifier = LM_LL;
	ptr = va_arg(state->list, void *);
	val = (unsigned long long)ptr;
	return (print_val(&val, PT_UINT, &params));
}
