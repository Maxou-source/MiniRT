/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:17:21 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 17:02:04 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	print_matrix_pirate(t_m4 a)
{
	int	i;
	int	j;

	i = 0;
	printf("matrixxxxx\n");
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f ", a[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_matrix_pirate3(t_m3 a)
{
	int	i;
	int	j;

	i = 0;
	printf("matrixxxxx\n");
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%f ", a[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

void	print_matrix_pirate2(t_m2 a)
{
	int	i;
	int	j;

	i = 0;
	printf("matrixxxxx\n");
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			printf("%f ", a[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

void	print_tuple(t_f4 f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("%.3f ", f[i]);
		i++;
	}
	printf("\n");
}
