/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:19:20 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/11 20:26:16 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_udigits_count(unsigned long long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_ulong_itoa(unsigned long long int n)
{
	int				i;
	char			*s;
	unsigned long long int	nb;

	nb = n;
	i = ft_udigits_count(n) - 1;
	s = ft_strnew((size_t)(i + 1));
	if (s == NULL)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	while (nb != 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (s);
}

char				*u_modificator(t_printf *prnt)
{
	char			*c;
	unsigned long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, unsigned long int);
		c = ft_ulong_itoa(ln);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, unsigned long long int);
		c = ft_long_itoa(ln);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (unsigned short int)va_arg(prnt->arg, unsigned int);
		c = ft_ulong_itoa(ln);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (unsigned char)va_arg(prnt->arg, unsigned int);
		c = ft_ulong_itoa(ln);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_ulong_itoa(ln);
	}
	return (c);
}

void		u_intger(t_printf *prnt)
{
	char	*c;

	c = u_modificator(prnt);
	unsigned_process_width(prnt, c);
}