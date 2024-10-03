/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:32:29 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:25 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTR_ARRAY_H
# define PTR_ARRAY_H

# include <stddef.h>
# include <stdlib.h>

// #ifndef PTR_ARRAY_MIN_CAPACITY
# define PTR_ARRAY_MIN_CAPACITY	8
// #endif

typedef struct s_ptr_array
{
	size_t	size;
	size_t	capacity;
	void	**array;
}				t_ptr_array;

t_ptr_array	pa_new(void);
size_t		pa_size(t_ptr_array pa);
void		pa_init(t_ptr_array *pa);
void		pa_add(void *ptr, t_ptr_array *pa);
void		pa_delete(t_ptr_array *pa);

#endif
