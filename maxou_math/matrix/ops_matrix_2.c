/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_matrix_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:46:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 17:28:03 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4	scaling_matrix(float x, float y, float z)
{
	t_m4	res;

	res = build_identity_matrix();
	res[0][0] = x;
	res[1][1] = y;
	res[2][2] = z;
	return (res);
}

// this serves the same purpose as multiplying two tuples
// together

t_m4	matrix(t_f4 a, t_f4 b, t_f4 c, t_f4 d)
{
	t_m4	res;

	res[0][0] = a.x;
	res[1][0] = a.y;
	res[2][0] = a.z;
	res[3][0] = a.w;
	res[0][1] = b.x;
	res[1][1] = b.y;
	res[2][1] = b.z;
	res[3][1] = b.w;
	res[0][2] = c.x;
	res[1][2] = c.y;
	res[2][2] = c.z;
	res[3][2] = c.w;
	res[0][3] = d.x;
	res[1][3] = d.y;
	res[2][3] = d.z;
	res[3][3] = d.w;
	return (res);
}

t_m4	orientation_matrix(t_f4 orientation)
{
	t_m4	res;
	t_f4	q;
	t_f4	a;
	float	t;

	t = acos(dot_product(point(0, 1, 0, 0), orientation));
	a = normalization(cross_product(point(0, 1, 0, 0), orientation));
	q.x = cos(t);
	q.y = sin(t);
	q.z = 1.0 - q.x;
	res = matrix_transpose(matrix(point(q.z * a.x * a.x + q.x,
					q.z * a.x * a.y - q.y * a.z,
					q.z * a.x * a.z + q.y * a.y, 0),
				point(q.z * a.x * a.y + q.y * a.z,
					q.z * a.y * a.y + q.x,
					q.z * a.y * a.z - q.y * a.x, 0),
				point(q.z * a.x * a.z - q.y * a.y, q.z * a.y * a.z + q.y * a.x,
					q.z * a.z * a.z + q.x, 0),
				point(0, 0, 0, 1)));
	return (res);
}

/*
This functions seems to be useless for now
leaving commented out for now 
if I ever need them I will commented them in
*/

// t_m4	rotation_matrix_x(float r)
// {
// 	t_m4	res;

// 	res = build_identity_matrix();
// 	res[1][1] = cos(r);
// 	res[2][2] = cos(r);
// 	res[2][1] = sin(r);
// 	res[1][2] = -sin(r);
// 	return (res);
// }

// t_m4	rotation_matrix_y(float r)
// {
// 	t_m4	res;

// 	res = build_identity_matrix();
// 	res[0][0] = cos(r);
// 	res[0][2] = sin(r);
// 	res[2][0] = -sin(r);
// 	res[2][2] = cos(r);
// 	return (res);
// }

// t_m4	rotation_matrix_z(float r)
// {
// 	t_m4	res;

// 	res = build_identity_matrix();
// 	res[0][0] = cos(r);
// 	res[0][1] = -sin(r);
// 	res[1][0] = sin(r);
// 	res[1][1] = cos(r);
// 	return (res);
// }
