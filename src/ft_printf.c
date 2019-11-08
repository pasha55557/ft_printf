/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/08 18:10:14 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					putchar_and_count(t_printf *prnt, char c)
{
	prnt->buff[prnt->count] = c;
	prnt->count++;
}

void		parser(t_printf *prnt)
{
	prnt->count = 0;
	prnt->width = 0;

	while (*prnt->format != '\0')
	{
		if (*prnt->format == '%')
		{
			if (PRO_TRUE == (prnt->flags & PRO_TRUE) && (FORM_TRUE != (prnt->flags & FORM_TRUE)))
			{
				prnt->flags |= DOUBLE_PRO;
			}
			prnt->format++;
			if_procent(prnt);
		}
		else
		{
			putchar_and_count(prnt, *prnt->format);
		}
		if (*prnt->format != '\0' && *prnt->format != '%')
			prnt->format++;
	}
	va_end(prnt->arg);
}


int	ft_printf(const char *format, ...)
{
	t_printf	*prnt;

	prnt = (t_printf*)malloc(sizeof(t_printf));
	prnt->format = format; 
	prnt->buff = (char*)malloc(sizeof(char) * 255);
	va_start(prnt->arg, format);
	parser(prnt);
	return(prnt->count);
}