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


typedef struct s_parser_state
{
	const char *fmt;
	va_list list;
}t_parser_state;

int ft_printf(const char *fmt, ...);

#endif
