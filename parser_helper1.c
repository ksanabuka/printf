#include "parser.h"

int			read_flags(t_parser_state *state)
{
	int flags;

	flags = 0;
	while (1)
	{
		if (*state->fmt == ' ')
			flags |= F_SPACE;
		else if (*state->fmt == '0')
			flags |= F_ZERO;
		else if (*state->fmt == '-')
			flags |= F_MINUS;
		else if (*state->fmt == '+')
			flags |= F_PLUS;
		else if (*state->fmt == '#')
			flags |= F_DIEZ;
		else
			break ;
		++state->fmt;
	}
	return (flags);
}

int			read_width_or_preci_val(t_parser_state *state)
{
	int w;

	w = 0;
	if (*state->fmt == '*')
	{
		++state->fmt;
		w = va_arg(state->list, int);
	}
	else
	{
		while (*state->fmt >= '0' && *state->fmt <= '9')
		{
			w = 10 * w + (*state->fmt - '0');
			++state->fmt;
		}
	}
	return (w);
}

int			read_width(t_parser_state *state)
{
	return (read_width_or_preci_val(state));
}

int			read_preci(t_parser_state *state)
{
	int p;

	p = -1;
	if (*state->fmt == '.')
	{
		++state->fmt;
		p = read_width_or_preci_val(state);
	}
	return p;
}

enum e_len_modifier	read_len_modifier(t_parser_state *state)
{
	if (state->fmt[0] == 'l' || state->fmt[0] == 'L')
	{
		if (state->fmt[0] == 'L')
			return (LM_CL);
		return (state->fmt[1] == 'l' || state->fmt[1] == 'L' ? LM_LL : LM_L);
	}
	if (state->fmt[0] == 'h')
		return (state->fmt[1] == 'h' ? LM_HH : LM_H);
	if (state->fmt[0] == 'z')
	{
		if (sizeof(size_t) == sizeof(long))
			return (LM_L);
		else if (sizeof(size_t) == sizeof(long long))
			return (LM_LL);
	}
	if (state->fmt[0] == 'j')
	{
		if (sizeof(intmax_t) == sizeof(long))
			return (LM_L);
		else if (sizeof(intmax_t) == sizeof(long long))
			return (LM_LL);
	}
	return (LM_DEFAULT);
}