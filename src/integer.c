/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:46:01 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:10:51 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*mod_l(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, long int);
	c = ft_long_itoa((long long int)ln);
	return (c);
}

static char			*mod_ll(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, long long int);
	c = ft_long_itoa(ln);
	return (c);
}

static char			*mod_h(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	ln = (short int)va_arg(prnt->arg, int);
	c = ft_long_itoa((long long int)ln);
	return (c);
}

char				*modificator(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
		c = mod_l(prnt);
	else if (MOD_LL == (prnt->flags & MOD_LL))
		c = mod_ll(prnt);
	else if (MOD_H == (prnt->flags & MOD_H))
		c = mod_h(prnt);
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

void				ft_intger(t_printf *prnt)
{
	char			*c;

	c = modificator(prnt);
	process_width(prnt, c);
}
