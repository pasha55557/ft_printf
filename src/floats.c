/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:04:21 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/24 17:40:47 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	itg_mult(char *local, int i)
{
	int		j;
	int		max;

	max = 1;
	j = 0;
	while (i--)
	{
		j = 0;
		while (j < max)
			local[j++] *= 2;
		j = -1;
		while (++j < max)
		{
			if (local[j] >= 10)
			{
				local[j + 1]++;
				local[j] %= 10;
				if (j + 1 == max)
					max++;
			}
		}
	}
}

void	add_func(char *itg, int i)
{
	int		j;
	char	local[5000];

	j = -1;
	ft_bzero(local, 5000);
	i = t_floats.t_bits.exp - 16383 - i;
	local[0] = 1;
	itg_mult(local, i);
	while (++j < 5000)
		itg[j] += local[j];
	j = -1;
	while (++j < 5000)
	{
		if (itg[j] >= 10)
		{
			itg[j] %= 10;
			itg[j + 1]++;
		}
	}
}

char	*count_itg(int bits)
{
	char	*itg;
	int		i;

	itg = (char *)ft_memalloc(5000);
	i = bits;
	while (i--)
	{
		if (t_floats.t_bits.mant & (1L << (63 - i)))
			add_func(itg, i);
	}
	i = 4999;
	while (itg[i] == 0)
		i--;
	while (i + 1)
	{
		itg[i] += '0';
		i--;
	}
	return (itg);
}

char	*ft_if_negative(char *res)
{
	char	*res_fin;

	res_fin = res;
	if (t_floats.t_bits.sign == 1)
	{
		res_fin = (char *)ft_memalloc(ft_strlen(res) + 2);
		res_fin[0] = '-';
		ft_strcat(res_fin, res);
		ft_strdel(&res);
	}
	return (res_fin);
}

char	*ft_flt(long double d, t_printf *prnt)
{
	char	*itg;
	char	*flt;
	int		x;
	char	*res;

	t_floats.f = d;
	flt = NULL;
	x = t_floats.t_bits.exp - 16383;
	if (x >= 63)
		itg = count_itg(64);
	else if (x < 0)
	{
		flt = print_flt(64);
		itg = (char *)ft_memalloc(2);
		itg[0] = '0';
	}
	else
	{
		itg = count_itg(x + 1);
		flt = print_flt(63 - x);
	}
	res = rounding_flt(itg, flt, prnt);
	res = ft_if_negative(res);
	ft_strdel(&itg);
	return (res);
}
