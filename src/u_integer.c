/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:19:20 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/10 19:57:33 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*u_modificator(t_printf *prnt)
{
	char			*c;
	long long int	ln;

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

void		u_intger(t_printf *prnt)
{
	char	*c;

	c = u_modificator(prnt);
	unsigned_process_width(prnt, c);
}