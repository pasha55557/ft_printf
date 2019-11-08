/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/08 16:30:24 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		parser(t_printf *prnt)
{
	prnt->count = 0;
	prnt->width = 0;

	while (*prnt->format != '\0')
	{
		if (*prnt->format == '%')
		{
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