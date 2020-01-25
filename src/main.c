/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/25 20:03:23 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <float.h>

int	main()
{
	// static unsigned int		mx_u = 235;
	// static long double			mx_Lf = 0.375l;
	// static double				mx_f = 0.625;
	// static long				mx_li =  4223372036854775800;
	// static long long			mx_lli = 3223372036654775200;
	// static char				mx_c = 'G';
	// static short				mx_hi = -3244;
	// static char				mx_hhi = 'F';
	// char				   *mx_s = "Hello, World!";
	// static int					mx_i = 42;
	int 	ft_i;
	int 	j;
	double	*f;
	long	l_f;
	int		d;
	char	*format = "%Lf\n";

	d = 54;
	l_f = DBL_NAN;
	f = (double *)&l_f;
	ft_i = printf(format, DBL_NAN);
	j = ft_printf(format, DBL_NAN);
	ft_printf("\\n");
	ft_printf("%%\\n");
	ft_printf("%d\\n", 42);
	ft_printf("%d%d\\n", 42, 41);
	ft_printf("%d%d%d\\n", 42, 43, 44);
	ft_printf("%ld\\n", 2147483647);
	ft_printf("%lld\\n", 9223372036854775807);
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);
	ft_printf("%20.15d\\n", 54321);
	ft_printf("%-10d\\n", 3);
	ft_printf("% d\\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%010d\\n", 1);
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%u\\n", 4294967295);
	ft_printf("%o\\n", 40);
	ft_printf("%%#08x\\n", 42);
	ft_printf("%x\\n", 1000);
	ft_printf("%#X\\n", 1000);
	ft_printf("%s\\n", NULL);
	ft_printf("%S\\n", L"ݗݜशব");
	ft_printf("%s%s\\n", "test", "test");
	ft_printf("%s%s%s\\n", "test", "test", "test");
	ft_printf("%C\\n", 15000);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}
