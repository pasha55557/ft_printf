/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:42:14 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 18:29:59 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int								width(t_printf *prnt)
{
	int							tmp;

	tmp = 0;
	if (*prnt->format >= '0' && *prnt->format <= '9')
	{
		prnt->width = ft_atoi_nb(prnt->format, &tmp);
		prnt->format += tmp;
		return (1);
	}
	return (0);
}

static int						if_procent2(t_printf *prnt)
{
	if (mods(prnt))
	{
		prnt->format++;
		return (1);
	}
	return (0);
}

static int						if_procent3(t_printf *prnt)
{
	form(prnt);
	if (FORM_TRUE == (prnt->flags & FORM_TRUE))
	{
		transform(prnt);
		prnt->format++;
		return (1);
	}
	return (0);
}

void							if_procent5(t_printf *prnt)
{
	prnt->flags |= PRO_TRUE;
	if (!(FORM_TRUE == (prnt->flags & FORM_TRUE)) &&
	(prnt->width != 0) &&
	(FLAG_MINUS != (prnt->flags & FLAG_MINUS)))
	{
		prnt->herna = 1;
		prnt->width--;
		unsigned_process_width(prnt, "\0");
	}
}

void							if_procent(t_printf *prnt)
{
	int							temp;

	temp = 0;
	prnt->format++;
	while (*prnt->format != '\0' && *prnt->format != '%' &&
	(!(FORM_TRUE == (prnt->flags & FORM_TRUE))))
	{
		if (flags(prnt) && if_procent4(prnt))
			continue;
		if (width(prnt))
			continue;
		if (accuracy(prnt))
			continue;
		if (!(MODS_TRUE == (prnt->flags & MODS_TRUE)))
			if (if_procent2(prnt))
				continue;
		if (!(FORM_TRUE == (prnt->flags & FORM_TRUE)))
			if (if_procent3(prnt))
				continue;
		if (*prnt->format != 'l' && *prnt->format != 'L'
		&& *prnt->format != 'h')
			putchar_and_count(prnt, *prnt->format);
		prnt->format++;
	}
	if_procent5(prnt);
}
