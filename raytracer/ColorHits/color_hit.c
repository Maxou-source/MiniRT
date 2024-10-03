/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:05:44 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/27 16:34:37 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

t_intrsct	*intersect_world(t_figure *w, t_ray *r, int add)
{
	int						i;
	t_intrsct**const		tab[2] = {&w->ins, &w->intersection};

	i = 0;
	while (w->sphere[i].identifier[0])
	{
		hit_sp(*r, &w->sphere[i], w, add);
		i++;
	}
	i = 0;
	while (w->cylinder[i].identifier[0])
	{
		hit_cy(*r, &w->cylinder[i], w, add);
		i++;
	}
	i = 0;
	while (w->plan[i].identifier[0])
	{
		hit_pl(*r, &w->plan[i], w, add);
		i++;
	}
	return (find_correct_intrsct(tab[add]));
}

/*
	the return values are probably not well organized but i struggled 
	to take the risk changing it
*/
bool	is_shaded(t_figure *w, t_f4 point, t_light *light)
{
	t_f4			v;
	float			distance;
	t_f4			direction;
	t_ray			r;
	t_intrsct		*in;

	v = light->point - point;
	distance = magnitude(v);
	direction = normalization(v);
	r.direction = direction;
	r.origin = point;
	in = 0;
	in = intersect_world(w, &r, 0);
	if (in)
	{
		if (distance != 0 && in->t < distance)
		{
			return (true);
		}
		return (false);
	}
	return (false);
}

void	delete_lst(t_figure *w)
{
	lst_inter_lstclear(&w->intersection);
	w->intersection = 0;
}

t_f4	color_hit(t_figure *w, t_ray *r)
{
	t_f4			color_px;
	int				j;
	t_intrsct		*in;

	color_px = point(0, 0, 0, 0);
	in = intersect_world(w, r, 1);
	if (!in)
	{
		if (w->intersection)
			delete_lst(w);
		return (color_px);
	}
	in->point = in->point + scalar_tuple(in->normalv,
			EPSILON * 100.0);
	j = -1;
	while (w->light[++j].identifier[0])
	{
		in->in_shadow = is_shaded(w, in->point, &w->light[j]);
		color_px += phong_lighting2(*in, &w->light[j]);
		lst_inter_lstclear(&w->ins);
		w->ins = 0;
	}
	delete_lst(w);
	return (color_px);
}
