/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:18:06 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:18:48 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				putstr_and_count(t_printf *prnt, char *c)
{
	if (prnt->count % 255 == 0 && prnt->count != 0)
		write(1, prnt->buff, 255);
	while (*c != '\0')
	{
		prnt->buff[prnt->count % 255] = *c;
		prnt->count++;
		c++;
	}
}

int					ftft_digits_count(long long int n)
{
	int				i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void			ft_dec_to2(t_dec_to *dec, unsigned long long int d, int sys)
{
	if (d == 0)
	{
		dec->c[dec->i] = '0';
		dec->i++;
	}
	while (d)
	{
		dec->c[dec->i] = 48 + d % sys;
		if (dec->c[dec->i] > 57)
			dec->c[dec->i] += dec->otc;
		d /= sys;
		dec->i++;
	}
}

char				*ft_dec_to(unsigned long long int d,
					int sys, t_printf *prnt)
{
	t_dec_to		dec;

	dec.j = 0;
	dec.otc = 39;
	if (FORM_X == (prnt->flags & FORM_X))
		dec.otc = 7;
	dec.i = 0;
	dec.c = malloc(sizeof(char) * 30);
	ft_dec_to2(&dec, d, sys);
	dec.i--;
	dec.s = malloc(sizeof(char) * dec.i);
	while (dec.i >= 0)
	{
		dec.s[dec.j] = dec.c[dec.i];
		dec.i--;
		dec.j++;
	}
	dec.s[dec.j] = '\0';
	ft_strdel(&dec.c);
	return (dec.s);
}
