/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:11:37 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 17:17:07 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include "main.h"

// ops_tuples.c
bool	equal(float a, float b);
bool	equal_tuple(t_f4 a, t_f4 b);
t_f4	adding_tuple(t_f4 a, t_f4 b);
t_f4	substracting_tuple(t_f4 a, t_f4 b);
t_f4	negating_tuple(t_f4 a);

// ops_tuples_2.c
float	magnitude(t_f4 a);
t_f4	normalization(t_f4 a);
float	dot_product(t_f4 a, t_f4 b);
t_f4	cross_product(t_f4 a, t_f4 b);

// ops_tuples_3.c
t_f4	scalar_tuple(t_f4 a, float b);
t_f4	adding_scalar_tuple(t_f4 a, float b);
t_f4	new_position(t_ray ray, float time);
t_f4	point(float x, float y, float z, float vector_point);

// color_utils.c
int		float_to_rgba(t_f4 color);
t_f4	r2f(t_clr	rgb);

#endif