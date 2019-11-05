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
	if (n < 0)
		i++;
	
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

const char		*if_procent(t_printf *prnt, const char *format)
{
	int			temp;

	temp = 0;

	if (format[1] == '\0')
		return(format);
	format++;
	while (*format == ' ')
		format++;
	
	/*
	FOR WIDTH
	*/

	if ((*format >= '0' && *format <= '9') || *format == '-')
	{
		prnt->width = ft_atoi(format);
		format += countdigits(prnt->width);
	}
	
	/*
	FOR INT
	*/

	if (*format == 'd')
	{
		prnt->d = va_arg(prnt->arg, int);
		temp = countdigits(prnt->d);
		if (prnt->width > 0)
		{
			prnt->width -= temp;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width--;
			}
		}
		ft_putnbr(prnt->d);
		if (prnt->width < 0)
		{
			prnt->width += temp;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width++;
			}
		}
		prnt->count += temp;
	}

	/*
	FOR CHAR
	*/

	else if (*format == 'c')
	{
		prnt->c = (char)va_arg(prnt->arg, int);
		if (prnt->width > 0)
		{
			prnt->width--;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width--;
			}
		}
		putchar_and_count(prnt, prnt->c);
		if (prnt->width < 0)
		{
			prnt->width++;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width++;
			}
		}
	}

	else if (*format != '\0')
	{
		if (prnt->width > 0)
		{
			prnt->width--;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width--;
			}
		}
		putchar_and_count(prnt, *format);
		if (prnt->width < 0)
		{
			prnt->width++;
			while (prnt->width != 0)
			{
				putchar_and_count(prnt, ' ');
				prnt->width++;
			}
		}
	}
	return(format);
}

void		parser(t_printf *prnt, const char *format)
{
	prnt->count = 0;
	prnt->width = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = if_procent(prnt, format);
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