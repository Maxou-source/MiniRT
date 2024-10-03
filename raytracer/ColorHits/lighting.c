/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:20:55 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/22 17:18:10 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

t_f4	reflect(t_f4 in, t_f4 normal)
{
	t_f4	res;

	res = in - scalar_tuple(scalar_tuple(normal, 2), dot_product(in, normal));
	res.w = 0;
	return (res);
}

t_f4	diffuse(t_f4 eff_c, float lnormal)
{
	t_f4	diffuse;

	diffuse = scalar_tuple(scalar_tuple(eff_c, 0.7), lnormal);
	return (diffuse);
}

// i lightv reflectv l
t_f4	specular(t_f4 lightv, t_intrsct i, t_light *l)
{
	t_f4	reflectv;
	float	reflect_dot_eye;
	float	factor;

	reflectv = reflect(-lightv, i.normalv);
	reflect_dot_eye = dot_product(reflectv, i.eye);
	if (reflect_dot_eye < 0)
		return (point(0, 0, 0, 0));
	factor = powf(reflect_dot_eye, SHININESS);
	return (scalar_tuple(scalar_tuple(l->new_color, 0.9), factor));
}

t_f4	phong_lighting2(t_intrsct i, t_light *l)
{
	t_f4	eff_c;
	t_f4	lightv;
	t_f4	ambient;
	float	lnormal;

	eff_c = i.color * l->new_color;
	lightv = normalization(l->point - i.point);
	ambient = eff_c * scalar_tuple(r2f(l->abl.color), l->abl.ratio);
	lnormal = dot_product(lightv, i.normalv);
	if (i.in_shadow == true || lnormal <= 0)
		return (ambient);
	return (ambient + diffuse(eff_c, lnormal) + specular(lightv, i, l));
}
