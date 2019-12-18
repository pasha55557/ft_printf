/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:20:42 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/18 12:47:33 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*o_modificator(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, unsigned long int);
		c = ft_dec_to(ln, 8, prnt);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, unsigned long long int);
		c = ft_dec_to(ln, 8, prnt);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (unsigned short int)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to(ln, 8, prnt);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (unsigned char)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to(ln, 8, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_dec_to(ln, 8, prnt);
	}
	return (c);
}

void		o_intger(t_printf *prnt)
{
	char	*c;

	c = o_modificator(prnt);
	unsigned_process_width(prnt, c);
}