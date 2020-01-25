/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:49:59 by tjonella          #+#    #+#             */
/*   Updated: 2020/01/25 19:55:45 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	rounding_int_aft_flt(char *res, int i)
{
	while (i)
	{
		if (res[i - 2] - '0' == 10)
		{
			res[i - 2] = '0';
			res[i - 3]++;
		}
		else
			break ;
		i--;
	}
}

void	rounding_flt_4(char *res, int i, t_printf *prnt)
{
	int acc;

	acc = prnt->accuracy;
	while (acc--)
	{
		if (res[i] - '0' == 10)
		{
			res[i] = '0';
			if (acc != 0)
				res[i - 1]++;
			else
			{
				res[i - 2]++;
				rounding_int_aft_flt(res, i);
			}
		}
		i--;
	}
}

int		rounding_flt_3(char *res, char *flt, int i, int j)
{
	if (flt[j] > '5')
		res[i]++;
	else if (flt[j] == '5')
	{
		while ((j + 1) && flt[j] == '0')
			j--;
		if (j > -1)
			res[i]++;
	}
	return (i);
}

char	*rounding_flt_2(char *itg, char *flt, t_printf *prnt)
{
	char	*res;
	int		i;
	int		j;
	int		acc;

	i = ft_strlen(itg);
	if (prnt->accuracy == -2)
		prnt->accuracy = 6;
	acc = prnt->accuracy;
	res = (char *)ft_memalloc(i + prnt->accuracy + 2);
	ft_memcpy(res, ft_strrev(itg), i);
	res[i] = prnt->accuracy != 0 ? '.' : 0;
	j = 0;
	while (flt[j])
		j++;
	j--;
	while (acc--)
	{
		i++;
		res[i] = (j + 1) ? flt[j--] : '0';
	}
	rounding_flt_4(res, rounding_flt_3(res, flt, i, j), prnt);
	res[i + 1] = '\0';
	return (res);
}

char	*big_int(char *itg, t_printf *prnt)
{
	char	*res;
	int		i;
	int		acc;

	i = ft_strlen(itg);
	if (prnt->accuracy == -2)
		prnt->accuracy = 6;
	acc = prnt->accuracy;
	res = (char *)ft_memalloc(i + prnt->accuracy + 2);
	ft_memcpy(res, ft_strrev(itg), i);
	res[i] = prnt->accuracy != 0 ? '.' : 0;
	i++;
	while (acc--)
	{
		res[i] = '0';
		i++;
	}
	//free(itg);
	return (res);
}
