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

int		parser(va_list arg, const char *format)
{
	int	d;
	char c;
	int count;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				d = va_arg(arg, int);
				ft_putnbr(d);
				count += countdigits(d);
			}
			else if (*format == 'c')
			{
				c = (char)va_arg(arg, int);
				ft_putchar(c);
				count += 1;
			}
			else
			{
				ft_putchar(*format);
				count += 1;
			}
		}
		else
		{
			ft_putchar(*format);
			count += 1;
		}
		format++;
	}
	va_end(arg);
	return(count);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;

	va_start(arg, format);
	return(parser(arg, format));
}