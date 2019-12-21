/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:58:28 by tjonella          #+#    #+#             */
/*   Updated: 2019/12/21 20:15:47 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

void	mult_flt(int i, char *local)
{
	int		j;
	int		max;

	max = 1;
	while (i--)
	{
		j = 0;
		while (j < max)
			local[j++] *= 5;
		j = -1;
		while (++j < max)
		{
			if (local[j] >= 10)
			{
				local[j + 1] += local[j] / 10;
				local[j] %= 10;
				if (j + 1 == max)
					max++;
			}
		}
	}
}

void	add_to_flt(char *flt, int i, char *local, int exp)
{
	int		j;

	j = -1;
	i = ft_abs(t_floats.t_bits.exp - 16383) - i + 63;
	ft_bzero(local, exp);
	local[0] = 1;
	mult_flt(i, local);
	while (++j < exp)
		flt[j] += local[j];
	j = -1;
	while (++j < exp)
	{
		if (flt[j] >= 10)
		{
			flt[j + 1] += flt[j] / 10;
			flt[j] %= 10;
		}
	}
}

void	bias_digit(char *flt, int i, int exp)
{
	int		j;

	while (i--)
	{
		j = exp - 1;
		while (j > 0 && flt[j] == 0)
			j--;
		j++;
		while (j--)
			flt[j + 1] = flt[j];
		flt[0] = 0;
	}
}

void	count_flt(char *flt, int exp, int bits)
{
	int		i;
	char	*local;
	int		bias_val;

	i = bits;
	bias_val = 0;
	local = (char *)ft_memalloc(sizeof(char) * exp);
	while (i--)
	{
		bias_val++;
		if (t_floats.t_bits.mant & (1L << i))
		{
			bias_digit(flt, bias_val, exp);
			add_to_flt(flt, i, local, exp);
			bias_val = 0;
		}
	}
	free(local);
}
char	*print_flt(int bits)
{
	char	*flt;
	int		exp;
	int		i;

	exp = ft_abs(t_floats.t_bits.exp - 16383) + 63;
	flt = (char *)ft_memalloc(sizeof(char) * exp + 1);
	ft_bzero(flt, exp);
	count_flt(flt, exp, bits);
	i = exp;
	while (i--)
		flt[i] += '0';
	flt[exp] = '\0';
	return (flt);
}