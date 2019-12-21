/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:04:21 by tjonella          #+#    #+#             */
/*   Updated: 2019/12/22 00:19:00 by tjonella         ###   ########.fr       */
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
	int				j;
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

void	rounding_int_aft_flt(char *res, int i)
{
	while (i)
	{
		if (res[i - 1] - '0' == 10)
		{
			res[i - 1] = '0';
			res[i - 2]++;
		}
		else
			break;
		i--;
	}
}
void	rounding_flt_4(char *res, int i, int acc)
{
	while (acc--)
	{
		if (res[i + 1] - '0' == 10)
		{
			res[i + 1] = '0';
			if (acc != 0)
				res[i]++;
			else
			{
				res[i - 1]++;
				rounding_int_aft_flt(res, i);
			}
		}
		i--;
	}
}

void	rounding_flt_3(char *res, char *flt, int i, int j, t_printf *prnt)
{
	int		acc;

	acc = prnt->accuracy;
	if (flt[j] > '5')
		res[i + 1]++;
	else
	{
		while ((j + 1) && flt[j] == '0')
			j--;
		if (j > -1)
			res[i + 1]++;
	}
	rounding_flt_4(res, i, acc);
}

char	*rounding_flt_2(char *itg, char *flt, t_printf *prnt)
{
	char	*res;
	int		i;
	int		j;
	int		acc;

	i = ft_strlen(itg);
	acc = prnt->accuracy;
	res = (char *)ft_memalloc(i + prnt->accuracy + 3);
	res[0] = 0;
	ft_memcpy(res + 1, itg, i);
	res[i + 1] = '.';
	j = 0;
	while (flt[j])
		j++;
	j--;
	while (acc--)
	{
		i++;
		res[i + 1] = flt[j--];
	}
	if (flt[j] >= '5')
		rounding_flt_3(res, flt, i, j, prnt);
	res[i + 2] = '\0';
	return (res);
}

char	*rounding_flt(char *itg, char *flt, t_printf *prnt)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (!flt)
		return (itg);
	while (flt[i])
		i++;
	if (prnt->accuracy <= 0 && flt[i] > '5')
		itg[0]++;
	else if (prnt->accuracy <= 0 && flt[i] == 5)
	{
		while ((i + 1) && flt[i] != '0')
			i--;
		if (i > -1)
			itg[0]++;
	}
	else
		res = rounding_flt_2(itg, flt, prnt);
	free(flt);
	return (res ? res : itg);
}

char	*ft_flt(long double d, t_printf *prnt)
{
	int		i;
	char	*itg;
	char	*flt;
	int		x;
	char	*res;

	i = 0;
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
		return (itg);
		flt = print_flt(63 - x);
	}
	res = rounding_flt(itg, flt, prnt);
	return (res);
}
