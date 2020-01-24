/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:37:34 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:04:54 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					process_width1(t_printf *prnt, char *c, int *count)
{
	int acc;

	acc = *count;
	if (c[0] == '-')
		acc--;
	if ((FLAG_PLUS == (prnt->flags & FLAG_PLUS) ||
	FLAG_SPACE == (prnt->flags & FLAG_SPACE)) && (c[0] != '-'))
		(*count)++;
	if (prnt->accuracy == 0 && *c == '0')
	{
		(*count)--;
		if (prnt->width == 0)
			prnt->accuracy = -4;
		else
			prnt->accuracy = -3;
	}
	if (prnt->accuracy >= 0)
	{
		prnt->accuracy -= acc;
		if (prnt->accuracy > 0)
			(*count) += prnt->accuracy;
		else
			prnt->accuracy = -2;
	}
}

static void					process_width2(t_printf *prnt, char *c, int *count)
{
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) &&
	(FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= (*count);
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
	if (FLAG_SPACE == (prnt->flags & FLAG_SPACE) &&
	(FLAG_PLUS != (prnt->flags & FLAG_PLUS)))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, ' ');
	}
}

static void					process_width3(t_printf *prnt, char *c, int *count)
{
	while (prnt->accuracy > 0)
	{
		putchar_and_count(prnt, '0');
		prnt->accuracy--;
	}
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) &&
	FLAG_MINUS != (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= (*count);
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
			putchar_and_count(prnt, *c);
		c++;
	}
}

void						process_width(t_printf *prnt, char *c)
{
	char	*ptr;
	int		count;

	ptr = c;
	count = 0;
	count = ft_strlen(c);
	
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && (prnt->accuracy >= 0))
		prnt->flags -= FLAG_NULL;
	process_width1(prnt, c, &count);
	process_width2(prnt, c, &count);
	process_width3(prnt, c, &count);
	if (FLAG_MINUS == (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
	ft_strdel(&ptr);
}