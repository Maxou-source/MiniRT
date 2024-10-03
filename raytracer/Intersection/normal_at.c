/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:05:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 20:22:51 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

/*
Notes about the normal vector:

to calculate the normal vector of a sphere which is not origin centered:

I need to convert the point given in world_space to object_space 
(where the origin is the center of the object)

in - normal * 2 * dot(in, normal)
*/

t_f4	normal_at(t_object *m, t_f4 p)
{
	t_f4	object_point;
	t_f4	object_normal;
	t_f4	world_normal;
	t_f4	tmp;

	object_point = matrix_tuple(m->i_m, p);
	object_normal = object_point - point(0, 0, 0, 1);
	world_normal = matrix_tuple(m->t_m, object_normal);
	tmp = normalization(world_normal);
	world_normal.w = 0;
	return (tmp);
}

t_f4	normal_at_pl(t_object *m, t_f4 p)
{
	t_f4	world;

	(void) p;
	world = matrix_tuple(m->t_m, point(0, 1, 0, 0));
	world.w = 0;
	return (normalization(world));
}

t_f4	normal_at_cy(t_object *obj, t_f4 p)
{
	t_f4	local;
	t_f4	world;
	float	dist;

	local = matrix_tuple(obj->i_m, p);
	dist = (local.x * local.x) + (local.z * local.z);
	if (dist < 1 && (local.y >= ((obj->hgt / 2) - EPSILON)))
		world = point(0, 1, 0, 0);
	else if (dist < 1 && (local.y <= (-(obj->hgt / 2) + EPSILON)))
		world = point(0, -1, 0, 0);
	else
	{
		local.y = 0;
		local.w = 0;
	}
	world = matrix_tuple(obj->t_m, local);
	world.w = 0;
	return (normalization(world));
}
