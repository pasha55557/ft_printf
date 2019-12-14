/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:56:32 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/14 19:32:25 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		transform(t_printf *prnt)
{
	if (FORM_D_I == (prnt->flags & FORM_D_I))
		ft_intger(prnt);
	else if (FORM_U == (prnt->flags & FORM_U))
		u_intger(prnt);
	else if (FORM_O == (prnt->flags & FORM_O))
		o_intger(prnt);
	else if (FORM_X == (prnt->flags & FORM_X) || FORM_x == (prnt->flags & FORM_x))
		x_intger(prnt);
	else if (FORM_C == (prnt->flags & FORM_C))
		ft_char(prnt);
	else if (FORM_s == (prnt->flags & FORM_s))
		ft_str(prnt);
	else if (FORM_P == (prnt->flags & FORM_P))
		ft_ptr(prnt);
	else if (FORM_N == (prnt->flags & FORM_N))
		ft_ptr_n(prnt);
}