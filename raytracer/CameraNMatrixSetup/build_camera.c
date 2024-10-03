/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:00:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/26 18:58:37 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

t_m4	view_transform(t_f4 from, t_f4 forward, t_f4 up)
{
	t_f4	leftv;
	t_f4	true_up;
	t_m4	res;

	leftv = cross_product(forward, normalization(up));
	if (equal_tuple(leftv, point(0, 0, 0, 0)))
	{
		leftv = cross_product(forward, point(0, 0, 1, 0));
		if (equal_tuple(leftv, point(0, 0, 0, 0)))
			leftv = cross_product(forward, point(1, 0, 0, 0));
	}
	true_up = cross_product(leftv, forward);
	res = build_identity_matrix();
	res[0][0] = leftv.x;
	res[0][1] = leftv.y;
	res[0][2] = leftv.z;
	res[1][0] = true_up.x;
	res[1][1] = true_up.y;
	res[1][2] = true_up.z;
	res[2][0] = -forward.x;
	res[2][1] = -forward.y;
	res[2][2] = -forward.z;
	return (res * translated_matrix(-from.x, -from.y, -from.z));
}

void	build_camera(t_camera *cam)
{
	cam->half_view = (cam->fov * PI) / 180.0;
	cam->aspect_ratio = WIN_WIDTH / WIN_HEIGHT;
	if (cam->aspect_ratio >= 1)
	{
		cam->half_width = cam->half_view;
		cam->half_height = cam->half_view / cam->aspect_ratio;
	}
	else
	{
		cam->half_width = cam->half_view * cam->aspect_ratio;
		cam->half_height = cam->half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / WIN_WIDTH;
	cam->transform = view_transform(cam->viewpoint,
			normalization(cam->orientation), point(0, 1, 0, 0));
	cam->inv_transform = inverted_matrix(cam->transform);
}

void	ray_for_pixel(t_camera *cam, int px, int py, t_ray *r)
{
	float	world_x;
	float	world_y;
	t_f4	world_point;
	t_f4	pixel;

	world_x = cam->half_width - (((float)px + 0.5) * cam->pixel_size);
	world_y = cam->half_height - (((float)py + 0.5) * cam->pixel_size);
	world_point = point(world_x, world_y, -1.0, 1.0);
	pixel = matrix_tuple(cam->inv_transform, world_point);
	r->origin.w = 1.0;
	r->origin = matrix_tuple(cam->inv_transform, point(0, 0, 0, 1.0));
	r->direction = normalization(pixel - r->origin);
	r->direction.w = 0;
}
