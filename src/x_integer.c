/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:57:23 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/11 17:59:38 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*x_modificator(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, unsigned long int);
		c = ft_dec_to((long long int)ln, 16, prnt);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, unsigned long long int);
		c = ft_dec_to(ln, 16, prnt);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (short int)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 16, prnt);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (char)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 16, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 16, prnt);
	}
	return (c);
}

void		x_intger(t_printf *prnt)
{
	char	*c;

	c = x_modificator(prnt);
	unsigned_process_width(prnt, c);
}

void						ft_ptr(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = va_arg(prnt->arg, ptrdiff_t);
	c = ft_dec_to(ln, 16, prnt);
	unsigned_process_width(prnt, c);
}

void						ft_ptr_n(t_printf *prnt)
{
	int						*ln;

	ln = va_arg(prnt->arg, int*);
	*ln = prnt->count;
	//c = ft_dec_to(ln, 16, prnt);
	//unsigned_process_width(prnt, c);
}
