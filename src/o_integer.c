/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:20:42 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/10 17:07:58 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*ft_dec_to(unsigned long long int d, int sys)
{
	char			*c;
	int				i;

	i = 0;
	c = malloc(sizeof(char) * 20);
	while (d)
	{
		c[i] = 48 + d % sys;
		if (c[i] > 57)
			c[i] += 7;
		d /= sys;
		i++;
	}
	return (c);
}

char				*o_modificator(t_printf *prnt)
{
	char			*c;
	long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, unsigned long int);
		c = ft_dec_to((long long int)ln, 8);
	}
	else if (MOD_LL == (prnt->flags & MOD_LL))
	{
		ln = va_arg(prnt->arg, unsigned long long int);
		c = ft_dec_to(ln, 8);
	}
	else if (MOD_H == (prnt->flags & MOD_H))
	{
		ln = (short int)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 8);
	}
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (char)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 8);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_dec_to((long long int)ln, 8);
	}
	return (c);
}

void		o_intger(t_printf *prnt)
{
	char	*c;

	c = o_modificator(prnt);
	process_width(prnt, c);
}