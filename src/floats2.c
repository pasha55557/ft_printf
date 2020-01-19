/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:58:28 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/19 18:57:45 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	i = ft_abs(t_floats.t_bits.exp - 16383 + i - 63);
	ft_bzero(local, exp);
	local[0] = 1;
	mult_flt(i, local);
	while (++j < exp)
		flt[j] += local[j];
	j = -1;
	while (++j < exp)
	{
		if (flt[j] >= 10 && flt[j] < '0')
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
	char	*local;
	int		bias_val;
	int		first_in;

	bias_val = 0;
	first_in = 1;
	local = (char *)ft_memalloc(sizeof(char) * exp);
	while (bits--)
	{
		bias_val++;
		if (t_floats.t_bits.mant & (1L << bits))
		{
			bias_digit(flt, bias_val, exp);
			add_to_flt(flt, bits, local, exp);
			if (first_in)
				first_bias(flt, bits, exp);
			first_in = 0;
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
	i = exp - 1;
	while ((i + 1) && flt[i] == 0)
		i--;
	while (i + 1)
	{
		if (flt[i] < 10)
			flt[i] += '0';
		i--;
	}
	flt[exp] = '\0';
	return (flt);
}
