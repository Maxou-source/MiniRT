/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_tuples_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:22:55 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 17:02:14 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	magnitude(t_f4 a)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res += a[i] * a[i];
		i++;
	}
	return (sqrtf(res));
}

t_f4	normalization(t_f4 a)
{
	float	b;
	t_f4	res;
	int		i;

	res = 0;
	b = magnitude(a);
	if (equal(b, 0))
		return (res);
	i = 0;
	while (i < 3)
	{
		res[i] = a[i] / b;
		i++;
	}
	return (res);
}
/*
the smaller the dot product the larger angle between the vectors
*/

float	dot_product(t_f4 a, t_f4 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/*
function cross(a, b)
return vector(a.y * b.z - a.z * b.y,
a.z * b.x - a.x * b.z,
a.x * b.y - a.y * b.x)
end function
*/
t_f4	cross_product(t_f4 a, t_f4 b)
{
	t_f4	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	res.w = 0;
	return (res);
}
