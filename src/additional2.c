/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:15:08 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/06 18:59:03 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		process_width_for_float(t_printf *prnt, char *c)
{
	char	*ptr;
	int		count;
	int		acc;
	unsigned char	tochka;

	tochka = 0;
	ptr = c;
	count = 0;
	count = ft_strlen(c);
	acc = count;
	if (c[0] == '-')
		acc--;
	if ((FLAG_PLUS == (prnt->flags & FLAG_PLUS) || FLAG_SPACE == (prnt->flags & FLAG_SPACE)) && (c[0] != '-'))
		count++;
//	if (prnt->accuracy == 0 && *c == '0')
//	{
//		count--;
//		if (prnt->width == 0)
//			prnt->accuracy = -4;
//		else
//			prnt->accuracy = -3;
//	}
	if (prnt->accuracy >= 0)
	{
		prnt->accuracy -= acc;
		if (prnt->accuracy > 0)
			count += prnt->accuracy;
		else
			prnt->accuracy = -2;
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
	if (c[0] == '-')
		putchar_and_count(prnt, '-');
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, '+');
	}
	if (FLAG_SPACE == (prnt->flags & FLAG_SPACE) && (FLAG_PLUS != (prnt->flags & FLAG_PLUS)))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, ' ');
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
	while (*c != '\0')
	{
		if (*c == '-')
			c++;
		if (prnt->accuracy > -3)
			if (*c == '.')
				tochka = 1;
			putchar_and_count(prnt, *c);
		c++;
	}
	if (FLAG_SHARP == (prnt->flags & FLAG_SHARP) && tochka == 0)
	{
		putchar_and_count(prnt, '.');
		count++;
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