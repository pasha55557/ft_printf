/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:46:01 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/01 19:32:12 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_intger(t_printf *prnt)
{
	int		d;
	char	*c;

	d = va_arg(prnt->arg, int);
	c = ft_itoa(d);
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS))
	{
		if (d > 0)
			putchar_and_count(prnt, '+');
	}
	else if (FLAG_SPACE == (prnt->flags & FLAG_SPACE))
	{
		if (d > 0)
			putchar_and_count(prnt, ' ');
	}
	while (*c != '\0')
	{
		putchar_and_count(prnt, *c);
		c++;
	}
}