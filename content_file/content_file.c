/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:30:55 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/22 16:04:40 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "content_file.h"
#include <stdio.h>

t_content_file	*cf_new(void)
{
	t_content_file	*cf;

	cf = ft_calloc(1, sizeof(t_content_file));
	if (cf)
	{
		cf -> line.size = 0;
		cf -> line.capacity = MIN_CONTENT_CAPICITY;
		cf -> line.content = malloc(cf -> line.capacity + 1);
		cf -> next = 0;
	}
	return (cf);
}

void	cf_add(char c, t_content_file *cf)
{
	if (cf -> line.size == cf -> line.capacity)
	{
		cf -> line.capacity *= 2;
		cf -> line.content = realloc(cf -> line.content, cf -> line.capacity);
	}
	cf -> line.content[cf -> line.size++] = c;
	if (c == '\0')
		cf -> line.begin = cf -> line.content;
}

void	cf_delete(t_content_file *cf)
{
	t_content_file	*tmp;

	tmp = cf;
	while (cf)
	{
		ft_memdel((void **)& cf -> line.begin);
		cf -> line.capacity = 0;
		cf -> line.size = 0;
		tmp = cf -> next;
		free(cf);
		cf = tmp;
	}
}

size_t	cf_size(t_content_file *cf)
{
	return (cf -> line.size);
}
