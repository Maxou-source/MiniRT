/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 06:08:02 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/22 16:59:47 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

# include "../maxou_math/includes/main.h"
// #ifndef AMBIENT_LIGHT_IDENTIFIER
# define AMBIENT_LIGHT_IDENTIFIER "A"
// #endif

// #ifndef CAMERA_IDENTIFIER
# define CAMERA_IDENTIFIER "C"
// #endif

// #ifndef LIGHT_IDENTIFIER
# define LIGHT_IDENTIFIER "L"
// #endif

// #ifndef SPHERE_IDENTIFIER
# define SPHERE_IDENTIFIER "sp"
// #endif

// #ifndef PLAN_IDENTIFIER
# define PLAN_IDENTIFIER "pl"
// #endif

// #ifndef CYLINDER_IDENTIFIER
# define CYLINDER_IDENTIFIER "cy"
// #endif

// #ifndef LEN_IDENTIFIER
# define LEN_IDENTIFIER 3
// #endif

// #ifndef EPSILON 
# define EPSILON 0.00001
// #endif

# define SP 0
# define CY 2
# define PL 1
# define ESC 65307

typedef float			t_vector __attribute__((ext_vector_type(3)));
/*
Bitch123#
we might need to change this to one have on type of variable
for points and vector

it will become

typedef float	t_vector __attribute__((ext_vector_type(4)));
the w will be one if its a point or zero if its a a vector

figure it out later
*/

typedef struct s_object	t_object;
typedef struct s_camera	t_camera;
typedef struct s_figure	t_figure;

typedef t_f4			(*t_normals)(t_object *obj, t_f4 p);

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win_ptr;
	int			width;
	int			height;
	int			**tab;
	t_img		*data;
	t_figure	*w;
	t_camera	*cam;
}		t_vars;

typedef struct s_ambient_light
{
	char		identifier[LEN_IDENTIFIER];
	t_clr		color;
	float		ratio;
}				t_ambient_light;

typedef struct s_camera
{
	char			identifier[LEN_IDENTIFIER];
	t_f4			viewpoint;
	t_f4			orientation;
	float			fov;

	float			half_view;
	float			aspect_ratio;
	float			half_width;
	float			half_height;
	float			pixel_size;
	t_m4			transform;
	t_m4			inv_transform;
}				t_camera;

typedef struct s_pattern
{
	float		space;
	t_clr		color;
	t_m4		m;
	t_m4		i_m;
	t_m4		t_m;
}	t_pattern;

typedef struct s_light
{
	char			identifier[LEN_IDENTIFIER];
	t_f4			point;
	t_clr			color;
	float			brightness;

	t_ambient_light	abl;
	t_f4			new_color;
}				t_light;
	// float		specular; // need to add to parsing
	// float		diffuse;
	// we might not need this

typedef struct s_object
{
	t_pattern	pat;
	t_m4		m;
	t_m4		i_m;
	t_m4		t_m;
	t_f4		clr;
	bool		pattern;
	int			id;
	float		hgt;
}	t_object;

typedef struct s_sphere
{
	char		identifier[LEN_IDENTIFIER];
	t_f4		origin;
	t_clr		color;
	float		diameter;
	float		specular;
	bool		pattern;

	t_object	obj;
	float		inter[2];
}				t_sphere;

typedef struct s_plan
{
	char		identifier[LEN_IDENTIFIER];
	t_f4		point;
	t_f4		orientation;
	t_clr		color;
	float		specular;
	bool		pattern;

	t_object	obj;
	float		inter[2];
}				t_plan;

typedef struct s_cylinder
{
	char		identifier[LEN_IDENTIFIER];
	t_f4		center;
	t_f4		cylinder_axis;
	float		diameter;
	float		height;
	t_clr		color;
	float		specular;
	bool		pattern;

	t_object	obj;
	float		inter[2];
}				t_cylinder;

typedef struct s_cube
{
	char		identifier[LEN_IDENTIFIER];
	t_f4		center;
	t_f4		cube_axis;
	float		height;
	t_clr		color;
	float		specular;
	bool		pattern;

	t_object	obj;
	float		inter[2];
}				t_cube;

// typedef	struct s_object
// {
// 	// matrices
// 	// color
// }

// Identifier 1 sphere
typedef struct s_intrsct
{
	float					t;
	int						identifier;

	t_f4					color;
	t_f4					point;
	t_f4					over_point;
	t_f4					eye;
	t_f4					normalv;
	bool					inside;
	bool					in_shadow;

	bool					cap;
	struct s_intrsct		*next;
}		t_intrsct;

typedef struct s_figure
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light[100];
	t_sphere		sphere[100];
	t_plan			plan[100];
	t_cylinder		cylinder[100];
	t_cube			cubes[100];

	t_intrsct		*intersection;
	t_intrsct		*ins;
}				t_figure;

#endif
