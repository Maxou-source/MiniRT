/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:40:25 by mparisse          #+#    #+#             */
/*   Updated: 2023/08/29 16:42:54 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "main.h"

// determinants.c
float	determinant_2b2(t_m2 matrix);
float	minor_f3(t_m3 m, int row, int column);
float	cofactor(t_m3 m, int row, int column);
float	cofactor4(t_m4 m, int row, int column);
float	determinant4(t_m4 m);

// prints.c 
void	print_matrix_pirate(t_m4 a);
void	print_matrix_pirate3(t_m3 a);
void	print_matrix_pirate2(t_m2 a);
void	print_tuple(t_f4 f);

// ops matrix
t_f4	matrix_tuple(t_m4 a, t_f4 b);
t_m4	matrix_transpose(t_m4 a);
t_m4	inverted_matrix(t_m4	m);
t_m4	build_identity_matrix(void);
t_m4	translated_matrix(float x, float y, float z);

// ops matrix 2
t_m4	scaling_matrix(float x, float y, float z);
t_m4	matrix(t_f4 a, t_f4 b, t_f4 c, t_f4 d);
t_m4	orientation_matrix(t_f4 orientation);
// commented out function (useless for now)
t_m4	rotation_matrix_x(float r);
t_m4	rotation_matrix_y(float r);
t_m4	rotation_matrix_z(float r);
// subs_matrix.c
t_m2	submatrix_f3(t_m3 matrix, int row, int column);
t_m3	submatrix_f4(t_m4 matrix, int row, int column);

// bool    equal_matrix(matrix2 a, matrix2 b);

#endif