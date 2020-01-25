/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:54:06 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 19:00:22 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char					*mod_l(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, unsigned long int);
	c = ft_ulong_itoa(ln);
	return (c);
}

static char					*mod_ll(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, unsigned long long int);
	c = ft_long_itoa(ln);
	return (c);
}

char						*u_modificator(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
		c = mod_l(prnt);
	else if (MOD_LL == (prnt->flags & MOD_LL))
		c = mod_ll(prnt);
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
