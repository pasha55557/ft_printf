/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2019/10/31 12:52:38 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		countdigits(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void		putchar_and_count(t_printf *prnt, char c)
{
	ft_putchar(c);
	prnt->count++;
}

const char		*if_pocent(t_printf *prnt, const char *format)
{
	format++;
	if (*format == 'd')
	{
		prnt->d = va_arg(prnt->arg, int);
		ft_putnbr(prnt->d);
		prnt->count += countdigits(prnt->d);
	}
	else if (*format == 'c')
	{
		prnt->c = (char)va_arg(prnt->arg, int);
		putchar_and_count(prnt, prnt->c);
	}
	else if (*format >= '0' && *format <= '9')
	{
		prnt->space = ft_atoi(format) - 1;
		format += countdigits(prnt->space) - 1;
		while (prnt->space != 0)
		{
			putchar_and_count(prnt, ' ');
			prnt->space--;
		}
	}
	else
	{
		putchar_and_count(prnt, *format);
	}
	return(format);
}


void		parser(t_printf *prnt, const char *format)
{
	prnt->count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = if_pocent(prnt, format);
		}
		else
		{
			putchar_and_count(prnt, *format);
		}
		format++;
	}
	va_end(prnt->arg);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*prnt;

	prnt = (t_printf*)malloc(sizeof(t_printf));
	va_start(prnt->arg, format);
	parser(prnt, format);
	return(prnt->count);
}