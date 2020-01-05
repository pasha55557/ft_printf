/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/06 02:22:40 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <float.h>

int	main()
{
	int 	ft_i;
	int 	j;
	float	f;

	f = 23.00041;
	ft_i = printf("%.f\n\n", 573.924);
	j = ft_printf("%.f", 573.924);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}