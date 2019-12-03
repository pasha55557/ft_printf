/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:46:01 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/03 18:42:44 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_intger(t_printf *prnt)
{
	int		d;
	char	*c;
	int		count;

	count = 0;
	d = va_arg(prnt->arg, int);
	c = ft_itoa(d);
	count = ft_strlen(c);
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS) && d >= 0)
		count++;
	if (prnt->accuracy > 0)
	{
		prnt->accuracy -= count;
		count += prnt->accuracy;
	}
	
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) && (FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}

	while (prnt->accuracy > 0)
	{
		putchar_and_count(prnt, '0');
		prnt->accuracy--;
	}
		
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && FLAG_MINUS != (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, '0');
			prnt->width--;
		}
	}
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
	if (FLAG_MINUS == (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
}