/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obuksha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:51:40 by obuksha           #+#    #+#             */
/*   Updated: 2019/02/06 10:51:58 by obuksha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *c, void (*f)(char *))
{
	if (!c || !f)
		return ;
	while (*c)
	{
		f(c);
		c++;
	}
}