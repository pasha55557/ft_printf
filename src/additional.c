/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:18:06 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/10 15:32:40 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_printf.h"

int		ftft_digits_count(long long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_long_itoa(long long int n)
{
	int				i;
	char			*s;
	long long int	nb;

	nb = n;
	i = ftft_digits_count(n) - 1;
	s = ft_strnew((size_t)(i + 1));
	if (s == NULL)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * (-1);
	}
	while (nb != 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (s);
}


void		process_width(t_printf *prnt, char *c)
{

	int		count;

	count = 0;
	count = ft_strlen(c);
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS) && c[0] != '-')
		count++;
	if (prnt->accuracy > 0)
	{
		prnt->accuracy -= count;
		count += prnt->accuracy;
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
	if (FLAG_PLUS == (prnt->flags & FLAG_PLUS))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, '+');
	}
	else if (FLAG_SPACE == (prnt->flags & FLAG_SPACE))
	{
		if (c[0] != '-' || c[0] == 0)
			putchar_and_count(prnt, ' ');
	}
	while (*c != '\0')
	{
		putchar_and_count(prnt, *c);
		c++;
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