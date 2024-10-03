/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:34:19 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/26 14:37:15 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ptr_array.h"

/*\*/
t_ptr_array	pa_new(void)
{
	return (t_ptr_array)
	{
		.size = 0,
		.capacity = 0,
		.array = malloc(sizeof(void *) * PTR_ARRAY_MIN_CAPACITY)
	};
}
/**/

void	pa_init(t_ptr_array *pa)
{
	*pa = pa_new();
}

void	pa_add(void *ptr, t_ptr_array *pa)
{
	if (pa -> size == pa -> capacity)
	{
		pa -> capacity *= 2;
		pa -> array = realloc(pa -> array, pa -> capacity * sizeof(void *));
		if (!pa -> array)
			return ;
	}
	pa -> array[pa -> size++] = ptr;
}

void	pa_delete(t_ptr_array *pa)
{
	pa -> size = 0;
	pa -> capacity = 0;
	free(pa -> array);
	pa -> array = 0;
}

size_t	pa_size(t_ptr_array pa)
{
	return (pa.size);
}
