/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:38:48 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 17:25:49 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define EPSILON 0.00001
# define PI 3.141592653589793

// COLORS
// ambient = 0.1
// diffuse = 0.9
// specular = 0.9
// shininess = 200
# define AMBIENT 0.1
# define DIFFUSE 0.9
# define SPECULAR 0.9
# define SHININESS 200.0

// different types of tuples for colors, points and vector
typedef float	t_f4 __attribute__((ext_vector_type(4)));
// typedef int int4 __attribute__((ext_vector_type(4)));

typedef struct s_ray
{
	t_f4	origin;
	t_f4	direction;
}	t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_clr;

// matrices 
typedef float	t_m2 __attribute__((matrix_type(2, 2)));
typedef float	t_m4 __attribute__((matrix_type(4, 4)));
typedef float	t_m3 __attribute__((matrix_type(3, 3)));

#endif