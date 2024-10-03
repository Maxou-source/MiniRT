/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:30:23 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 21:22:51 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

void	hit_pl(t_ray r, t_plan *pl, t_figure *w, int add)
{
	t_ray					new;
	float					t;
	t_intrsct**const		tab[2] = {&w->ins, &w->intersection};

	new.origin = matrix_tuple(pl->obj.i_m, r.origin);
	new.direction = matrix_tuple(pl->obj.i_m, r.direction);
	if (equal(new.direction.y, 0) || equal(new.origin.y, 0))
	{
		return ;
	}
	t = (-new.origin.y) / new.direction.y;
	if (t < 0)
		return ;
	creating_intersection_lst(&r, tab[add], t, &pl->obj);
	return ;
}
