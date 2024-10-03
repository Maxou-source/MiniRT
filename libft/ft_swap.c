/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:33:51 by nxoo              #+#    #+#             */
/*   Updated: 2023/09/26 14:35:34 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_mini_swap(float *a, float *b)
{
	float	keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

void	ft_swap(void *a, void *b, size_t const n)
{
	size_t			i;
	unsigned char	*cur_a;
	unsigned char	*cur_b;
	unsigned char	tmp;

	i = 0;
	while (i < n)
	{
		cur_a = a + i;
		cur_b = b + i;
		tmp = *cur_a;
		*cur_a = *cur_b;
		*cur_b = tmp;
		i++;
	}
}
