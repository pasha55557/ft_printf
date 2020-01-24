/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:12:38 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 14:28:27 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					init_prnt(t_printf *prnt)
{
	prnt->herna = 0;
	prnt->width = 0;
	prnt->accuracy = -2;
	prnt->flags = 0;
}

void					putchar_and_count(t_printf *prnt, char c)
{
	if (prnt->count % 255 == 0 && prnt->count != 0)
		write(1, prnt->buff, 255);
	prnt->buff[prnt->count % 255] = c;
	prnt->count++;
}
