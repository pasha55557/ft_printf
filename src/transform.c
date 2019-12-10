/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:56:32 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/10 17:01:54 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		transform(t_printf *prnt)
{
	if (FORM_D_I == (prnt->flags & FORM_D_I))
	{
		ft_intger(prnt);
	}
	if (FORM_U == (prnt->flags & FORM_U))
	{
		u_intger(prnt);
	}
	if (FORM_O == (prnt->flags & FORM_O))
	{
		o_intger(prnt);
	}
}