/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:32:29 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/22 01:35:12 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_FILE_H
# define CONTENT_FILE_H

# include "libft.h"
# include <math.h>

// #ifndef MIN_CONTENT_CAPICITY
# define MIN_CONTENT_CAPICITY	20
// #endif

// #ifndef MAX_CONTENT_READ
# define MAX_CONTENT_READ	1
// #endif

typedef struct s_line
{
	size_t	capacity;
	size_t	size;
	size_t	skipped;
	char	*content;
	char	*begin;
	char	identifier[3];
	int		identifier_id;
}				t_line;

typedef struct s_content_file
{
	struct s_line			line;
	struct s_content_file	*next;
}				t_content_file;

t_content_file	*cf_new(void);
size_t			cf_size(t_content_file *cf);
void			cf_add(char c, t_content_file *cf);
void			cf_delete(t_content_file *cf);

#endif
