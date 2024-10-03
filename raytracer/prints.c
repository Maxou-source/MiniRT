/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:04:50 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 21:18:48 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

void	print_intrsct(t_intrsct *inter)
{
	printf("it intersected at : ");
	printf("%.3f distance from the originn\n", inter->t);
	printf("intersection point : ");
	print_tuple(inter->point);
	printf("eye vector :");
	print_tuple(inter->eye);
	printf("normalv :");
	print_tuple(inter->normalv);
}
// printf("the intersection is %s\n", (inter->inside > 0) ? 
// "inside\n\n" : "not inside\n\n");

void	print_camera(t_camera *cam)
{
	printf("my camera origin is ");
	print_tuple(cam->viewpoint);
	printf("orientation camera : ");
	print_tuple(cam->orientation);
	printf("half view	  : %f\n", cam->half_view);
	printf("half height	: %f\n", cam->half_height);
	printf("half width	 : %f\n", cam->half_width);
	printf("aspect ratio   : %f\n", cam->aspect_ratio);
}

void	print_ray(t_ray *r)
{
	printf("ray origin : ");
	print_tuple(r->origin);
	printf("ray direction : ");
	print_tuple(r->direction);
}
