/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:35 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 16:59:17 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m2	submatrix_f3(t_m3 matrix, int row, int column)
{
	t_m2	res;
	int		ii;
	int		jj;
	int		i;
	int		j;

	ii = 0;
	jj = 0;
	i = -1;
	while (++i < 3)
	{
		if (i != row)
		{
			jj = 0;
			j = -1;
			while (++j < 3)
			{
				if (j != column)
					res[ii][jj++] = matrix[i][j];
			}
			ii++;
		}
	}
	return (res);
}

t_m3	submatrix_f4(t_m4 matrix, int row, int column)
{
	t_m3	res;
	int		ii;
	int		jj;
	int		i;
	int		j;

	ii = 0;
	jj = 0;
	i = -1;
	while (++i < 4)
	{
		if (i != row)
		{
			jj = 0;
			j = -1;
			while (++j < 4)
			{
				if (j != column)
					res[ii][jj++] = matrix[i][j];
			}
			ii++;
		}
	}
	return (res);
}
