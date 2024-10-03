/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:27:51 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/27 16:00:38 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

int	hit_sp_end(t_ray ray, t_sphere *sphere, t_figure *w, int add)
{
	t_intrsct**const	tab[2] = {&w->ins, &w->intersection};

	if (sphere->inter[0] > 0)
		creating_intersection_lst(&ray, tab[add], sphere->inter[0],
			&sphere->obj);
	if (sphere->inter[1] > 0)
		creating_intersection_lst(&ray, tab[add], sphere->inter[1],
			&sphere->obj);
	return (0);
}

void	hit_sp(t_ray ray, t_sphere *sphere, t_figure *w, int add)
{
	t_f4					ray_to_sphere;
	t_ray					new;
	float					discriminant;
	float					a;
	float					b;

	new.origin = matrix_tuple(sphere->obj.i_m, ray.origin);
	new.direction = matrix_tuple(sphere->obj.i_m, ray.direction);
	ray_to_sphere = new.origin - point(0, 0, 0, 1);
	a = dot_product(new.direction, new.direction);
	b = 2 * dot_product(new.direction, ray_to_sphere);
	discriminant = 0;
	discriminant = (b * b) - (4.0 * a
			* (dot_product(ray_to_sphere, ray_to_sphere) - 1.0));
	if (discriminant > 0.0)
	{
		sphere->inter[0] = ((-b - sqrtf(discriminant)) / (2 * a));
		sphere->inter[1] = ((-b + sqrtf(discriminant)) / (2 * a));
		hit_sp_end(ray, sphere, w, add);
	}
}
