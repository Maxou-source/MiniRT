/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:46:06 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/26 19:15:32 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "../maxou_math/includes/main.h"
# include "figure.h"
# include "../mlx/mlx.h"
# include <inttypes.h>
# include <stdint.h>
# include <signal.h>
# include <stdio.h>

# define WIN_HEIGHT 800.0
# define WIN_WIDTH 800.0

// main
void			garbage(void *new, int i);
void			init_mlx(t_vars *vars, t_img *img, t_figure *w,
					t_camera *camera);
void			render(t_camera *camera, t_figure *w);

// RAYTRACER

// CameraNMatrixSetup
// build_camera.c
t_m4			view_transform(t_f4 from, t_f4 forward, t_f4 up);
void			build_camera(t_camera *cam);
void			ray_for_pixel(t_camera *cam, int px, int py, t_ray *r);

// build_transform.c
void			build_obj(t_object *obj, t_f4 origin, t_f4 orientv, float diam);
void			build_lights(t_figure *w);
void			build_transform_matrix(t_figure *w);

// ColorHits
// color_hit.c
t_intrsct		*intersect_world(t_figure *w, t_ray *r, int add);
bool			is_shaded(t_figure *w, t_f4 point, t_light *light);
t_f4			color_hit(t_figure *w, t_ray *r);

// lighting.c
t_f4			reflect(t_f4 in, t_f4 normal);
t_f4			diffuse(t_f4 eff_c, float lnormal);
t_f4			specular(t_f4 lightv, t_intrsct i, t_light *l);
t_f4			phong_lighting2(t_intrsct i, t_light *l);

// Hits
void			hit_sp(t_ray ray, t_sphere *sphere, t_figure *w, int add);
void			hit_pl(t_ray r, t_plan *pl, t_figure *w, int add);
void			hit_cy(t_ray r, t_cylinder *cy, t_figure *w, int add);

// Intersection
// lst_intrscts.c
void			lst_inter_lstclear(t_intrsct **lst);
t_intrsct		*ft_lstlast_in(t_intrsct *lst);
void			lst_inter_addback(t_intrsct **lst, t_intrsct *new);
int				creating_intersection_lst(t_ray *r, t_intrsct **w,
					float t, t_object *obj);
t_intrsct		*find_correct_intrsct(t_intrsct **lst);
// normal_at.c
t_f4			normal_at(t_object *m, t_f4 p);
t_f4			normal_at_pl(t_object *m, t_f4 p);
t_f4			normal_at_cy(t_object *obj, t_f4 p);

// mlx_utils
int				keyhook(int key_code, t_vars *vars);
int				ft_close(t_vars *vars);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				init_img(t_img *img, void *mlx);
// prints
void			print_intrsct(t_intrsct *inter);
void			print_ray(t_ray *r);
void			print_camera(t_camera *cam);

#endif