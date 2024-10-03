/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_transform_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:52:20 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/22 17:00:22 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

void	build_obj(t_object *obj, t_f4 origin, t_f4 orientv, float diam)
{
	t_m4	orient;
	t_m4	trans;
	t_m4	scale;

	orient = build_identity_matrix();
	scale = build_identity_matrix();
	if (obj->id >= 1)
		orient = orientation_matrix(normalization(orientv));
	trans = translated_matrix(origin.x, origin.y, origin.z);
	if (obj->id == CY || obj->id == SP)
		scale = scaling_matrix(diam, (obj->id == CY) + (obj->id == 0) * diam,
				diam);
	obj->m = trans * orient * scale;
	obj->i_m = inverted_matrix(obj->m);
	obj->t_m = matrix_transpose(obj->i_m);
}

void	build_lights(t_figure *w)
{
	int	i;

	i = 0;
	while (w->light[i].identifier[0])
	{
		w->light[i].new_color = r2f(w->light[i].color);
		w->light[i].abl = w->ambient_light;
		i++;
	}
}

void	build_transform_matrix(t_figure *w)
{
	static const int	jump[3] = {sizeof(t_sphere), sizeof(t_plan),
		sizeof(t_cylinder)};
	const void			*s[5] = {&w->sphere[0], &w->plan[0],
		&w->cylinder[0], 0, 0};
	const t_object		*objects[3] = {&w->sphere[0].obj, &w->plan[0].obj,
		&w->cylinder[0].obj};
	static int			i = -1;
	t_object			*o;

	while (++i < 3)
	{
		s[3] = s[i];
		o = (t_object *)objects[i];
		while (*(char *)s[3])
		{
			o->id = i;
			build_obj(o, *(t_f4 *)(s[3] + 16), *(t_f4 *)(s[3]
					+ 32), *(float *)(s[3] + 44 + (4 * (i > PL))));
			o->hgt = *(float *)(s[3] + 16 * 3 + 4);
			o->clr = r2f(*(t_clr *)(s[3] + 16 * (2 + (i > SP)) + 8 * (i > PL)));
			o = (t_object *)((long)o + (long)jump[i]);
			s[3] = s[3] + jump[i];
		}
	}
	build_lights(w);
}
