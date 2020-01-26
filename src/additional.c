/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:18:06 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/26 15:50:37 by tjonella         ###   ########.fr       */
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

int					ft_atoi_nb(const char *str, int *nb)
{
	struct s_atoi	a;

	a.nb = 0;
	a.m = 1;
	a.i = 0;
	a.g = 0;
	while (str[a.i] == '\t' || str[a.i] == '\n' || str[a.i] == '\v'
			|| str[a.i] == '\f' || str[a.i] == ' '
			|| str[a.i] == '\r')
		a.i++;
	if (str[a.i] == '-' || str[a.i] == '+')
		if (str[a.i++] == '-')
			a.m = -1;
	while (str[a.i + a.g] >= '0' && str[a.i + a.g] <= '9')
	{
		a.nb = a.nb * 10 + (str[a.i + a.g] - '0');
		a.g++;
	}
	*nb = a.g;
	if ((a.nb <= 9223372036854775807) && (a.g <= 19))
		return (((int)a.nb) * a.m);
	else if (a.m > 0)
		return (-1);
	return (0);
}
