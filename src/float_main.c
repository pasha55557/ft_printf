/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:31:07 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/06 17:13:21 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*modif_flt(t_printf *prnt)
{
	char			*c;
	long double 	lln;
	double			ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((double)ln, prnt);
	}
	else if (MOD_LLL == (prnt->flags & MOD_LLL))
	{
		lln = va_arg(prnt->arg, long double);
		c = ft_flt((long double)lln, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, double);
		c = ft_flt((double)ln, prnt);
	}
	return (c);
}

void	ft_flt_get(t_printf *prnt)
{
	char	*c;

	c = modif_flt(prnt);
	//process_width(prnt, c);
	process_width_for_float(prnt, c);
}