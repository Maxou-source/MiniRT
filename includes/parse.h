/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:04:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/22 16:04:53 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "content_file.h"
# include "figure.h"
# include <stdio.h>

typedef struct s_readfile
{
	t_content_file	*cf;
	t_content_file	*cf_tmp;
	char			tmp[MAX_CONTENT_READ + 1];
	int				rd[2];
}	t_readfile;

// #ifndef EXTENSION_FILENAME
# define EXTENSION_FILENAME	".rt"
// #endif

// #ifndef MAX_PARAMETERS
# define MAX_PARAMETERS 6
// #endif

typedef bool	(*t_fill_infos)(char *, void *structure);

//	parse.c
t_content_file	*readfile(const char *filename, t_figure *infos);
bool			check_extension_filename(const char *filename);

// parse_line.c
char			*get_data(t_line *const line);
bool			parse_line(t_content_file *node, t_figure *infos);

// set_data.c
bool			set_clr(const char *s, int *const ptr,
					t_line *const line, bool add);
char			*set_vector(char *s, float *const ptr);

//parse_utils.c
bool			update_ptr(t_line *const line);
bool			parse_ambient_line(t_line *line, void *const ptr);

// print parsing
void			print_content_file(const t_content_file *cf);
void			print_figure_structs(const t_figure infos);

#endif
