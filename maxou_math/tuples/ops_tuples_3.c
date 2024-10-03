/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_tuples_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:15:07 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/02 19:12:29 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_f4	scalar_tuple(t_f4 a, float b)
{
	int		i;
	t_f4	res;

	i = 0;
	while (i < 4)
	{
		res[i] = a[i] * b;
		i++;
	}
	return (res);
}

t_f4	adding_scalar_tuple(t_f4 a, float b)
{
	int		i;
	t_f4	res;

	i = 0;
	while (i < 3)
	{
		res[i] = a[i] + b;
		i++;
	}
	return (res);
}

t_f4	new_position(t_ray ray, float time)
{
	t_f4	m;

	m = ray.origin + scalar_tuple(ray.direction, time);
	m.w = 1;
	return (m);
}

t_f4	point(float x, float y, float z, float vector_point)
{
	t_f4	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = vector_point;
	return (res);
}
