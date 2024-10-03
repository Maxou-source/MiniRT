/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_tuples.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:48 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 17:02:22 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	equal(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

bool	equal_tuple(t_f4 a, t_f4 b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!equal(a[i], b[i]))
			return (false);
		i++;
	}
	return (true);
}

t_f4	adding_tuple(t_f4 a, t_f4 b)
{
	t_f4	res;
	int		i;

	i = 0;
	while (i < 3)
	{
		res[i] = a[i] + b[i];
		i++;
	}
	return (res);
}

t_f4	substracting_tuple(t_f4 a, t_f4 b)
{
	t_f4	res;
	int		i;

	i = 0;
	while (i < 3)
	{
		res[i] = a[i] - b[i];
		i++;
	}
	return (res);
}

t_f4	negating_tuple(t_f4 a)
{
	int		i;
	t_f4	res;

	i = 0;
	while (i < 3)
	{
		res[i] = a[i] * -1;
		i++;
	}
	res.w = 0;
	return (res);
}
