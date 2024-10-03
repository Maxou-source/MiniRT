/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:14:58 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 19:33:07 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

// ((int) color.x << 16) | ((int) color.y << 8) | ((int) color.z)
// si jamais superieure a 1 alors ca vaut 1 sinon color.x
int	float_to_rgba(t_f4 color)
{
	int	r;
	int	g;
	int	b;

	r = (int)((((color.x > 1.0) * 1.0) + ((color.x <= 1.0) * color.x))
			* 255.0);
	g = (int)((((color.y > 1.0) * 1.0) + ((color.y <= 1.0) * color.y))
			* 255.0);
	b = (int)((((color.z > 1.0) * 1.0) + ((color.z <= 1.0) * color.z))
			* 255.0);
	return ((r << 16) | (g << 8) | b);
}

t_f4	r2f(t_clr	rgb)
{
	t_f4	res;

	res.x = (float)(rgb.r) / 255.0;
	res.y = (float)(rgb.g) / 255.0;
	res.z = (float)(rgb.b) / 255.0;
	res.w = 0;
	return (res);
}
