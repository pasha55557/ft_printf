/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2019/11/05 20:34:04 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		flags(t_printf *prnt)
{
	if (*prnt->format == '-')
		prnt->flags |= FLAG_MINUS;
	if (*prnt->format == ' ')
		prnt->flags |= FLAG_SPACE;
	if (*prnt->format == '+')
		prnt->flags |= FLAG_PLUS;
	if (*prnt->format == '#')
		prnt->flags |= FLAG_SHARP;
	if (*prnt->format == '0')
		prnt->flags |= FLAG_NULL;
}

void	width(t_printf *prnt)
{
	
}

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
	prnt->buff[prnt->count] = c;
	prnt->count++;
}

void		*if_procent(t_printf *prnt)
{
	int			temp;

	temp = 0;
	
	
	while (*prnt->format != '\0')
	{
		flags(prnt);

	/*
	FOR WIDTH
	*/

		if (*prnt->format >= '0' && *prnt->format <= '9')
		{
			prnt->width = ft_atoi(prnt->format);
			prnt->format += countdigits(prnt->width);
		}
	
	/*
	FOR INT

	if (*prnt->format == 'd')
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
	*/

	/*
	FOR CHAR

	else if (*prnt->format == 'c')
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
	*/

	/*
	else if (*prnt->format != '\0')
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
		putchar_and_count(prnt, *prnt->format);
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
	*/
	prnt->format++;
	}
	
}



void		parser(t_printf *prnt)
{
	prnt->count = 0;
	prnt->width = 0;

	while (*prnt->format != '\0')
	{
		if (*prnt->format == '%')
		{
			prnt->format = if_procent(prnt);
		}
		else
		{
			putchar_and_count(prnt, *prnt->format);
		}
		if (*prnt->format != '\0')
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