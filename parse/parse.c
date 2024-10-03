/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:13:04 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/22 15:39:51 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "content_file.h"

bool	check_extension_filename(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 3)
		return (false);
	return (ft_strcmp((filename + i) - 3, EXTENSION_FILENAME) == 0);
}

bool	init_readfile(int *rd, const char *filename, t_content_file **cf,
	t_content_file **cf_tmp)
{
	rd[0] = open(filename, O_RDONLY);
	if (rd[0] < 0)
		return (false);
	rd[1] = 1;
	*cf = cf_new();
	*cf_tmp = *cf;
	return (true);
}

t_content_file	*check_line(int *rd, t_content_file *cf, t_content_file *cf_tmp,
	t_figure *infos)
{
	if (cf_tmp -> line.size)
	{
		cf_add('\0', cf_tmp);
		if (!parse_line(cf_tmp, infos))
			return (close(rd[0]), cf_delete(cf), NULL);
		cf_tmp -> next = cf_new();
		cf_tmp = cf_tmp -> next;
	}
	return (cf_tmp);
}

t_content_file	*readfile(const char *filename, t_figure *infos)
{
	t_readfile	readf;

	if (!init_readfile(readf.rd, filename, &readf.cf, &readf.cf_tmp))
		return (NULL);
	while (readf.rd[1])
	{
		readf.rd[1] = read(readf.rd[0], readf.tmp, MAX_CONTENT_READ);
		if (readf.rd[1] < 0)
			return (cf_delete(readf.cf), close(readf.rd[0]), NULL);
		if (readf.rd[1] == 0)
			break ;
		if (*readf.tmp == '\n')
		{
			readf.cf_tmp = check_line(readf.rd, readf.cf, readf.cf_tmp, infos);
			if (!readf.cf_tmp)
				return (NULL);
			continue ;
		}
		cf_add(*readf.tmp, readf.cf_tmp);
	}
	close(readf.rd[0]);
	cf_add('\0', readf.cf_tmp);
	if (!parse_line(readf.cf_tmp, infos))
		return (cf_delete(readf.cf), NULL);
	return (readf.cf);
}
