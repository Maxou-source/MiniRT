/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:02:47 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 20:50:26 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

int	keyhook(int key_code, t_vars *vars)
{
	if (key_code == ESC)
		garbage(0, 1);
	(void) vars;
	return (0);
}

int	ft_close(t_vars *vars)
{
	(void) vars;
	garbage(0, 1);
	exit(0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	init_img(t_img *img, void *mlx)
{
	img->img = mlx_new_image(mlx, 800, 800);
	if (!img->img)
		garbage(0, 1);
	garbage(img->img, 0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (1);
}
