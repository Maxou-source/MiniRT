/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_intrscts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:48:08 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/21 17:10:55 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "geometry.h"

void	lst_inter_lstclear(t_intrsct **lst)
{
	t_intrsct	*new_lst;
	t_intrsct	*tmp;

	new_lst = *lst;
	while (new_lst)
	{
		tmp = new_lst->next;
		free(new_lst);
		new_lst = tmp;
	}
}

t_intrsct	*ft_lstlast_in(t_intrsct *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_inter_addback(t_intrsct **lst, t_intrsct *new)
{
	t_intrsct	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_in(*lst);
	tmp->next = new;
}

int	creating_intersection_lst(t_ray *r, t_intrsct **w,
	float t, t_object *obj)
{
	t_intrsct				*new;
	static const t_normals	func[3] = {& normal_at,
		&normal_at_pl, &normal_at_cy};

	new = calloc(sizeof(t_intrsct), 1);
	new->t = t;
	new->identifier = obj->id;
	new->eye = negating_tuple(r->direction);
	new->point = new_position(*r, t);
	new->normalv = func[obj->id](obj, new->point);
	new->color = obj->clr;
	if (dot_product(new->normalv, new->eye) < 0.0)
	{
		new->normalv = negating_tuple(new->normalv);
	}
	lst_inter_addback(w, new);
	return (0);
}

t_intrsct	*find_correct_intrsct(t_intrsct **lst)
{
	t_intrsct	*tmp;
	t_intrsct	*res;

	if (!*lst)
	{
		return (0);
	}
	tmp = *lst;
	res = *lst;
	while (tmp)
	{
		if (tmp->t > 0)
			break ;
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->t < res->t && (tmp->t > 0))
			res = tmp;
		tmp = tmp->next;
	}
	if (res->t < 0)
		return (0);
	return (res);
}
// int	get_floor(float x)
// {
// 	int floor;

// 	while (x < 0)
// 		x -= 1.0;
// 	floor = x;
// 	return floor;
// }
// t_f4	get_pattern(t_object *obj, t_f4 world)
// {
// 	t_f4 obj_point = matrix_tuple(obj->i_m, world);
// 	t_f4	pat_point = matrix_tuple(obj->pat.i_m, obj_point);
// 	if ((get_floor(pat_point.x) + get_floor(pat_point.y) +
//				get_floor(pat_point.z)) % 2 == 0)
// 	{
// 		return point(0,0,0,0);
// 	}
// 	else
// 		return obj->clr;
// }
/*
	-these functions use to serve to get a pattern shown on 
	the objects but it only worked for planes.
*/
