/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:54:35 by obuksha           #+#    #+#             */
/*   Updated: 2019/06/24 09:54:38 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_fmt_pms		init_fmt_params(void)
{
	t_fmt_pms	fmt;

	fmt.flags = 0;
	fmt.preci = -1;
	fmt.width = 0;
	fmt.width_wildcard = 0;
	fmt.len_modifier = LM_DEFAULT;
	fmt.int_base = 10;
	fmt.is_prfx_uppercase = 0;
	return (fmt);
}

int				update_fmt_flags(t_fmt_pms *fmt, char c)
{
	if (c == ' ')
		fmt->flags |= F_SPACE;
	else if (c == '0' && fmt->width == 0 && fmt->preci < 0)
		fmt->flags |= F_ZERO;
	else if (c == '-')
		fmt->flags |= F_MINUS;
	else if (c == '+')
		fmt->flags |= F_PLUS;
	else if (c == '#')
		fmt->flags |= F_DIEZ;
	else
		return (0);
	return (1);
}

int				update_fmt_len_modifier(t_fmt_pms *fmt, char c)
{
	if (c == 'L')
		fmt->len_modifier = (LM_CL);
	else if (c == 'l')
		fmt->len_modifier = (fmt->len_modifier == LM_L || \
		fmt->len_modifier == LM_LL ? LM_LL : LM_L);
	else if (c == 'h')
	{
		if (fmt->len_modifier == LM_DEFAULT || fmt->len_modifier == LM_H)
		{
			fmt->len_modifier = fmt->len_modifier == LM_H ? LM_HH : LM_H;
		}
	}
	else if (c == 'z' && sizeof(size_t) == sizeof(long))
		fmt->len_modifier = (LM_L);
	else if (c == 'z' && sizeof(size_t) == sizeof(long long))
		fmt->len_modifier = (LM_LL);
	else if (c == 'j' && sizeof(intmax_t) == sizeof(long))
		fmt->len_modifier = (LM_L);
	else if (c == 'j' && sizeof(intmax_t) == sizeof(long long))
		fmt->len_modifier = (LM_LL);
	else
		return (0);
	return (1);
}

int				update_fmt_width_and_preci(t_parser_state *state,\
				t_fmt_pms *fmt, char c)
{
	if (c == '.')
		fmt->preci = 0;
	else if (fmt->preci >= 0 && c >= '0' && c <= '9')
		fmt->preci = 10 * fmt->preci + (c - '0');
	else if (c >= '0' && c <= '9')
	{
		fmt->width = fmt->width_wildcard > 0 ? 0 : fmt->width;
		fmt->width_wildcard = 0;
		fmt->width = 10 * fmt->width + (c - '0');
	}
	else if (c == '*' && fmt->preci < 0)
	{
		fmt->width_wildcard = va_arg(state->list, int);
		fmt->width = fmt->width_wildcard;
		if (fmt->width < 0)
		{
			fmt->width = -fmt->width;
			fmt->flags |= F_MINUS;
		}
	}
	else if (c == '*' && fmt->preci >= 0)
		fmt->preci = va_arg(state->list, int);
	else
		return (0);
	return (1);
}

int				update_fmt(t_parser_state *state, t_fmt_pms *fmt, char c)
{
	return (update_fmt_flags(fmt, c) || update_fmt_len_modifier(fmt, c)\
			|| update_fmt_width_and_preci(state, fmt, c));
}
