/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_pro_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:36:54 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 16:37:00 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					unsigned_process_width2(t_printf *prnt,
							char *c, int acc, int *count)
{
	if (prnt->accuracy == 0 && *c == '0')
	{
		if (prnt->width == 0)
			prnt->accuracy = -4;
		else
			prnt->accuracy = -3;
	}
	if (prnt->accuracy >= 0)
	{
		if ((FORM_O == (prnt->flags & FORM_O) &&
			(FLAG_SHARP == (prnt->flags & FLAG_SHARP))) && c[0] != '0')
			prnt->accuracy--;
		prnt->accuracy -= acc;
		if (prnt->accuracy > 0)
			*count += prnt->accuracy;
		else
			prnt->accuracy = -2;
	}
}

static void					unsigned_process_width3(t_printf *prnt,
							char *c, int *count)
{
	if ((FLAG_SHARP == (prnt->flags & FLAG_SHARP) &&
	((*c != '0') || FORM_O == (prnt->flags & FORM_O))) ||
	(FORM_P == (prnt->flags & FORM_P)))
	{
		if ((!(FORM_O == (prnt->flags & FORM_O) &&
		(c[0] == '0'))) || (prnt->accuracy == -4))
			(*count)++;
		if (FORM_XX == (prnt->flags & FORM_XX) ||
		(FORM_P == (prnt->flags & FORM_P)))
			(*count)++;
		if (FORM_X == (prnt->flags & FORM_X))
			(*count)++;
	}
	if (FLAG_MINUS != (prnt->flags & FLAG_MINUS) &&
	(FLAG_NULL != (prnt->flags & FLAG_NULL)))
	{
		prnt->width -= *count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
}

static void					unsigned_process_width4(t_printf *prnt, char *c)
{
	if ((FLAG_SHARP == (prnt->flags & FLAG_SHARP) &&
	((*c != '0') || FORM_O == (prnt->flags & FORM_O))) ||
	(FORM_P == (prnt->flags & FORM_P)))
	{
		if ((!(FORM_O == (prnt->flags & FORM_O) &&
		(c[0] == '0'))) || (prnt->accuracy == -4))
			putchar_and_count(prnt, '0');
		if (FORM_XX == (prnt->flags & FORM_XX) ||
		(FORM_P == (prnt->flags & FORM_P)))
			putchar_and_count(prnt, 'x');
		if (FORM_X == (prnt->flags & FORM_X))
			putchar_and_count(prnt, 'X');
	}
	while (prnt->accuracy > 0)
	{
		putchar_and_count(prnt, '0');
		prnt->accuracy--;
	}
}

static void					unsigned_process_width5(t_printf *prnt,
							char *c, int *count)
{
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) &&
	FLAG_MINUS != (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= *count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, '0');
			prnt->width--;
		}
	}
	while (*c != '\0')
	{
		if (prnt->accuracy == -3 && (!(FORM_O == (prnt->flags & FORM_O) &&
		c[0] == '0' && FLAG_SHARP == (prnt->flags & FLAG_SHARP))))
			putchar_and_count(prnt, ' ');
		else if (prnt->accuracy == -4)
			prnt->accuracy = 0;
		else
			putchar_and_count(prnt, *c);
		c++;
	}
}

void						unsigned_process_width(t_printf *prnt, char *c)
{
	char					*ptr;
	int						count;
	int						acc;

	ptr = c;
	count = ft_strlen(c);
	acc = count;
	if (FLAG_NULL == (prnt->flags & FLAG_NULL) && (prnt->accuracy >= 0))
		prnt->flags -= FLAG_NULL;
	unsigned_process_width2(prnt, c, acc, &count);
	unsigned_process_width3(prnt, c, &count);
	unsigned_process_width4(prnt, c);
	unsigned_process_width5(prnt, c, &count);
	if (FLAG_MINUS == (prnt->flags & FLAG_MINUS))
	{
		prnt->width -= count;
		while (prnt->width > 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->width--;
		}
	}
	if (prnt->herna == 0)
		ft_strdel(&ptr);
}
