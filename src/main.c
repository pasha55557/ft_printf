/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/18 18:03:40 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int	main()
{
	int 	ft_i;
	int 	j;
	char	c;
	long long int 	d;
	double	f;
	int		*n;
	//int		*n2;
	//char 	*s = "HEllo Bitch";

	f = 0.006;
	d = -42;
	c = 'f';
	ft_i = 0;
	j = 0;
	n = malloc(sizeof(int) * 9);
	//n2 = malloc(sizeof(int)); //"%.2s is a string\n", "this" (u_int64_t)22337203685477
	//write(1, 256, 1); "%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p\n", n, n, n, n, n, n, n, n, n, n, n, n
	ft_i = printf("%5p\n", 0);
	//printf("\n my printf\n"); 
	//ft_i = printf("%d\n", *n);
	//ft_i = printf("(%5i)\n", d);
	//printf("%e",);
	j = ft_printf("%5p\n", 0); 
	//j = ft_printf("%d\n", *n2);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}