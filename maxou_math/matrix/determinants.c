/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:21:58 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 17:28:24 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float	determinant_2b2(t_m2 m)
{
	return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

float	minor_f3(t_m3 m, int row, int column)
{
	return (determinant_2b2(submatrix_f3(m, row, column)));
}

float	cofactor(t_m3 m, int row, int column)
{
	float	res;

	if (((row + column) % 2) != 0)
	{
		res = minor_f3(m, row, column) * -1;
		return (res);
	}
	return (minor_f3(m, row, column));
}

// pour avoir le cofactor de t_m4 0 0 ils suffit d'obtenir le cofactor
// de la submatrice t_m4 0 0 
float	cofactor4(t_m4 m, int row, int column)
{
	float	res;
	t_m3	sub;
	int		i;

	sub = submatrix_f4(m, row, column);
	res = 0;
	i = -1;
	while (++i < 3)
		res += cofactor(sub, 0, i) * sub[0][i];
	if (((row + column) % 2) != 0)
		return (res * -1);
	return (res);
}

float	determinant4(t_m4 m)
{
	float	res;
	float	cof;
	t_m3	sub3;
	int		i;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		sub3 = submatrix_f4(m, 0, i);
		cof = sub3[0][0] * (sub3[1][1] * sub3[2][2] - sub3[1][2] * sub3[2][1])
			- sub3[0][1] * (sub3[1][0] * sub3[2][2] - sub3[1][2] * sub3[2][0])
			+ sub3[0][2] * (sub3[1][0] * sub3[2][1] - sub3[1][1] * sub3[2][0]);
		if (i % 2)
			cof = cof * -1;
		res += (m[0][i] * cof);
	}
	return (res);
}
