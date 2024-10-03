/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:24:14 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 17:01:55 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_f4	matrix_tuple(t_m4 a, t_f4 b)
{
	t_f4	res;

	res = 0;
	res.x = a[0][0] * b.x + a[0][1] * b.y + a[0][2] * b.z + a[0][3] * b.w;
	res.y = a[1][0] * b.x + a[1][1] * b.y + a[1][2] * b.z + a[1][3] * b.w;
	res.z = a[2][0] * b.x + a[2][1] * b.y + a[2][2] * b.z + a[2][3] * b.w;
	res.w = a[3][0] * b.x + a[3][1] * b.y + a[3][2] * b.z + a[3][3] * b.w;
	return (res);
}

t_m4	matrix_transpose(t_m4 a)
{
	t_m4	res;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			res[j][i] = a[i][j];
		}
		i++;
	}
	return (res);
}

t_m4	inverted_matrix(t_m4 m)
{
	t_m4	cof_m;
	float	cof_tmp;
	float	det;
	int		i;
	int		j;

	det = determinant4(m);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			cof_tmp = cofactor4(m, i, j);
			cof_m[j][i] = cof_tmp / det;
			j++;
		}
		i++;
	}
	return (cof_m);
}

t_m4	build_identity_matrix(void)
{
	t_m4	res;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	}
	return (res);
}

t_m4	translated_matrix(float x, float y, float z)
{
	t_m4	id_m;

	id_m = build_identity_matrix();
	id_m[0][3] = x;
	id_m[1][3] = y;
	id_m[2][3] = z;
	return (id_m);
}
