/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:56:00 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/21 21:21:10 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int	main()
{
	int 	ft_i;
	int 	j;
	float	f;

	f = 1234.123;
	ft_i = printf("%f\n", f);
	j = ft_printf("%f", f);
	printf("\ncount printf     (%d)\n", ft_i);
	printf("count ft_printf  (%d)\n", j);
	return(0);
}