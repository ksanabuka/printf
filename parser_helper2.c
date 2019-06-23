#include "parser.h"

long long	read_int_val(t_parser_state *state,\
			enum e_len_modifier len_modifier)
{
	long long val;

	val = 0;
	if (len_modifier == LM_LL)
		val = va_arg(state->list, long long);
	else if (len_modifier == LM_L)
		val = va_arg(state->list, long);
	else if (len_modifier == LM_H)
		val = (short)va_arg(state->list, int);
	else if (len_modifier == LM_HH)
		val = (char)va_arg(state->list, int);
	else
		val = va_arg(state->list, int);
	return (val);
}

unsigned long long	read_uint_val(t_parser_state *state,\
					enum e_len_modifier len_modifier)
{
	unsigned long long	val;

	val = 0;
	if (len_modifier == LM_LL)
		val = va_arg(state->list, unsigned long long);
	else if (len_modifier == LM_L)
		val = va_arg(state->list, unsigned long);
	else if (len_modifier == LM_H)
		val = (unsigned short)va_arg(state->list, unsigned int);
	else if (len_modifier == LM_HH)
		val = (unsigned char)va_arg(state->list, unsigned int);
	else
		val = va_arg(state->list, unsigned int);
	return (val);
}

long double	read_real_val(t_parser_state *state,\
							enum e_len_modifier len_modifier)
{
	long double val;

	val = 0;
	if (len_modifier == LM_CL)
		val = va_arg(state->list, long double);
	else
		val = va_arg(state->list, double);
	return (val);
}

int	print_real(t_parser_state *state)
{
	t_fmt_pms		params;
	long double		val;

	params = read_format_params(state, 10, 0);
	val = read_real_val(state, params.len_modifier);
	return (print_val(&val, PT_REAL, &params));
}
