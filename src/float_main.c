/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:31:07 by tjonella          #+#    #+#             */
/*   Updated: 2019/12/21 23:13:09 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*modif_flt(t_printf *prnt)
{
	char			*c;
	long double 	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((long double)ln, prnt);
	}
	else if (MOD_LLL == (prnt->flags & MOD_LLL))
	{
		ln = va_arg(prnt->arg, long double);
		c = ft_flt((long double)ln, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((long double)ln, prnt);
	}
	return (c);
}

void	ft_flt_get(t_printf *prnt)
{
	char	*c;

	c = modif_flt(prnt);
	process_width(prnt, c);
}