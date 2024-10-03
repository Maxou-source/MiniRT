/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:33:14 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/27 15:56:52 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

int	check_cap(t_ray r, float g)
{
	float	x;
	float	z;
	float	t;

	x = r.origin.x + (g * r.direction.x);
	z = r.origin.z + (g * r.direction.z);
	t = ((x * x) + (z * z));
	if (equal(r.direction.y, 0))
		return (false);
	if (t <= 1)
		return (true);
	return (false);
}

int	check_caps(t_ray r, t_cylinder *cy, t_figure *w, int add)
{
	float					y;
	t_ray					new;
	t_intrsct**const		tab[2] = {&w->ins, &w->intersection};

	new.direction = matrix_tuple(cy->obj.i_m, r.direction);
	new.origin = matrix_tuple(cy->obj.i_m, r.origin);
	y = (-(cy->height / 2.0) - new.origin.y) / new.direction.y;
	if (check_cap(new, y) && y > 0)
		creating_intersection_lst(&r, tab[add], y, &cy->obj);
	y = ((cy->height / 2.0) - new.origin.y) / new.direction.y;
	if (check_cap(new, y) && y > 0)
		creating_intersection_lst(&r, tab[add], y, &cy->obj);
	return (0);
}

void	hit_cy_end(t_ray r, t_cylinder *cy, t_figure *w, int add)
{
	t_ray					new;
	t_intrsct**const		tab[2] = {&w->ins, &w->intersection};

	new.direction = matrix_tuple(cy->obj.i_m, r.direction);
	new.origin = matrix_tuple(cy->obj.i_m, r.origin);
	if (cy->inter[0] > cy->inter[1])
		ft_mini_swap(&cy->inter[0], &cy->inter[1]);
	if (fabs(new.origin.y + (cy->inter[0] * new.direction.y))
		< (cy->height / 2.0) && cy->inter[0] > 0)
		creating_intersection_lst(&r, tab[add], cy->inter[0], &cy->obj);
	if (fabs(new.origin.y + (cy->inter[1] * new.direction.y))
		< (cy->height / 2.0) && cy->inter[1] > 0)
		creating_intersection_lst(&r, tab[add], cy->inter[1], &cy->obj);
	check_caps(r, cy, w, add);
}

void	hit_cy(t_ray r, t_cylinder *cy, t_figure *w, int add)
{
	t_ray					new;
	float					f[2];
	float					disc;

	new.direction = matrix_tuple(cy->obj.i_m, r.direction);
	new.origin = matrix_tuple(cy->obj.i_m, r.origin);
	f[0] = (new.direction.x * new.direction.x) + (new.direction.z
			* new.direction.z);
	if (equal(f[0], 0.0))
		return ;
	f[1] = (2.0 * new.origin.x * new.direction.x)
		+ (2.0 * new.origin.z * new.direction.z);
	disc = (f[1] * f[1]) - (4.0 * f[0] * ((new.origin.x * new.origin.x)
				+ (new.origin.z * new.origin.z) - 1.0));
	if (disc > 0.0)
	{
		cy->inter[0] = ((-f[1] - sqrtf(disc)) / (2 * f[0]));
		cy->inter[1] = ((-f[1] + sqrtf(disc)) / (2 * f[0]));
		hit_cy_end(r, cy, w, add);
	}
}
