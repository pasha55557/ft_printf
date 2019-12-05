/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:46:01 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/05 19:30:52 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_digits_count(long long int n)
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

static char			*ft_long_itoa(long long int n)
{
	int				i;
	char			*s;
	long long int	nb;

	nb = n;
	i = ft_digits_count(n) - 1;
	s = ft_strnew((size_t)ft_digits_count(n));
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

static char		*u_modificator(t_printf *prnt)
{
	char 	*c;
	long long int ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, unsigned long int);
		c = ft_long_itoa((long long int)ln);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, unsigned long long int);
		c = ft_long_itoa(ln);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (short int)va_arg(prnt->arg, unsigned int);
		c = ft_long_itoa((long long int)ln);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (char)va_arg(prnt->arg, unsigned int);
		c = ft_long_itoa((long long int)ln);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_long_itoa((long long int)ln);
	}
	return (c);
}

static char		*modificator(t_printf *prnt)
{
	char 	*c;
	long long int ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, long int);
		c = ft_long_itoa((long long int)ln);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, long long int);
		c = ft_long_itoa(ln);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (short int)va_arg(prnt->arg, int);
		c = ft_long_itoa((long long int)ln);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (char)va_arg(prnt->arg, int);
		c = ft_long_itoa((long long int)ln);
	}
	else
	{
		ln = va_arg(prnt->arg, int);
		c = ft_long_itoa((long long int)ln);
	}
	return (c);
}

void		ft_intger(t_printf *prnt)
{
	char	*c;
	int		count;
	//long long int ln;

	count = 0;
	if (FORM_D_I == (prnt->flags & FORM_D_I))
		c = modificator(prnt);
	if (FORM_U == (prnt->flags & FORM_U))
		c = u_modificator(prnt);
	
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