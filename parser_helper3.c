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

int	print_int(t_parser_state *state, t_fmt_pms *fmt)
{
	long long val;

	val = read_int_val(state, fmt->len_modifier);
	return (print_val(&val, PT_INT, fmt));
}

int	print_uint(t_parser_state *state, t_fmt_pms *fmt, char spec)
{
	unsigned long long	val;

    if (spec == 'o' || spec == 'O')
        fmt->int_base = 8;
    else if (spec == 'x' || spec == 'X')
    {
        fmt->int_base = 16;
        fmt->is_prfx_uppercase = spec == 'X';
    }
    else if (spec == 'b' || spec == 'B')
        fmt->int_base = 2;
    else if (spec == 'u' || spec == 'U')
    {
        fmt->flags &= ~F_SPACE;
        if (spec == 'U')
            fmt->len_modifier = LM_LL;
    }
	val = read_uint_val(state, fmt->len_modifier);
	return (print_val(&val, PT_UINT, fmt));
}

int	print_char(t_parser_state *state, t_fmt_pms *fmt)
{
	char		c;

	fmt->flags &= ~F_SPACE;
	c = (char)va_arg(state->list, int);
	return (print_val(&c, PT_CHAR, fmt));
}

int	print_str(t_parser_state *state, char *val, t_fmt_pms *fmt)
{
	if (val)
	{
		fmt->flags &= ~F_SPACE;
		fmt->preci = -1;
	}
	else
		val = va_arg(state->list, char *);
	return (print_val(val, PT_STR, fmt));
}

int	print_ptr(t_parser_state *state, t_fmt_pms *fmt)
{
	unsigned long long	val;
	void				*ptr;

    fmt->int_base = 16;
	fmt->flags |= F_DIEZ;
    fmt->flags |= F_ALWAYS_PRINT_PREFIX;
	fmt->len_modifier = LM_LL;
	ptr = va_arg(state->list, void *);
	val = (unsigned long long)ptr;
	return (print_val(&val, PT_UINT, fmt));
}
