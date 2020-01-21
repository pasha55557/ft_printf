/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/21 19:47:39 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <float.h>

int	main()
{
	static unsigned int		mx_u = 235;
static long double			mx_Lf = 0.375l;
static double				mx_f = 0.625;
static long				mx_li =  4223372036854775800;
static long long			mx_lli = 3223372036654775200;
static char				mx_c = 'G';
static short				mx_hi = -3244;
static char				mx_hhi = 'F';
static char			   *mx_s = "Hello, World!";
static int					mx_i = 42;
	int 	ft_i;
	int 	j;
	double	*f;
	long	l_f;
	int		d;
	char	*format = "  %o    %x    %i    %c    %hi   %Lf\n";

	d = 54;
	l_f = DBL_NAN;
	f = (double *)&l_f;
	ft_i = printf(format, mx_u, mx_u, mx_i, mx_c, mx_hi, mx_Lf);
	j = ft_printf(format, mx_u, mx_u, mx_i, mx_c, mx_hi, mx_Lf);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}