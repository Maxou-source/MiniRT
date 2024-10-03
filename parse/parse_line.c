/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:00:34 by jewancti          #+#    #+#             */
/*   Updated: 2023/09/27 16:23:37 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_data(t_line *const line)
{
	char *const	s = line -> content;
	int			start;
	int			i;

	start = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	line -> skipped += i + 1;
	s[i] = 0;
	return (s + start);
}

bool	fill_struct_end(t_line *line, void *const ptr)
{
	if (! update_ptr(line))
		return (false);
	if (ft_strcmp(line -> identifier, CYLINDER_IDENTIFIER) == 0)
	{
		*(float *)(ptr + (sizeof(t_f4) * 2) + sizeof(float) + 12)
				= atof(get_data(line));
		if (! update_ptr(line))
			return (false);
		*(float *)(ptr + (sizeof(t_f4) * 2) + sizeof(float) + 16)
			= atof(get_data(line));
	}
	if (ft_strcmp(line -> identifier, LIGHT_IDENTIFIER) == 0
		|| ft_strcmp(line -> identifier, SPHERE_IDENTIFIER) == 0)
		return (set_clr(line -> content, ptr + sizeof(t_f4)
				+ sizeof(t_clr) + sizeof(float), line, true));
	if (ft_strcmp(line -> identifier, PLAN_IDENTIFIER) == 0)
		return (set_clr(get_data(line),
				ptr + (sizeof(t_f4) * 2) + sizeof(t_clr) + 4, line, false));
	return (update_ptr(line) && set_clr(get_data(line),
			ptr + (sizeof(t_f4) * 2) + (sizeof(float) * 2) + sizeof(t_clr) + 4,
			line, false));
}

bool	fill_struct(t_line *line, void *const ptr)
{
	line -> content += line -> skipped;
	if (ft_strcmp(line -> identifier, AMBIENT_LIGHT_IDENTIFIER) == 0)
		return (parse_ambient_line(line, ptr));
	if (! set_vector(get_data(line), ptr + sizeof(t_f4)) || ! update_ptr(line))
		return (false);
	if (ft_strcmp(line -> identifier, CAMERA_IDENTIFIER) == 0
		|| ft_strcmp(line -> identifier, PLAN_IDENTIFIER) == 0
		|| ft_strcmp(line -> identifier, CYLINDER_IDENTIFIER) == 0)
		if (! set_vector(get_data(line), ptr + (sizeof(t_f4) * 2)))
			return (false);
	if (! update_ptr(line))
		return (false);
	if (ft_strcmp(line -> identifier, PLAN_IDENTIFIER)
		&& ft_strcmp(line -> identifier, CYLINDER_IDENTIFIER))
	{
		*(float *)(ptr + (sizeof(t_f4) * 2) + sizeof(t_clr)
			+ (!ft_strcmp(line -> identifier, CAMERA_IDENTIFIER) * 4))
			= atof(get_data(line));
		if (ft_strcmp(line -> identifier, CAMERA_IDENTIFIER) == 0)
			return (true);
	}
	return (fill_struct_end(line, ptr));
}

static
bool	get_index_from_identifier(t_line *const line)
{
	const char *const	identifiers[MAX_PARAMETERS] = {
		AMBIENT_LIGHT_IDENTIFIER, CAMERA_IDENTIFIER, LIGHT_IDENTIFIER,
		SPHERE_IDENTIFIER, PLAN_IDENTIFIER, CYLINDER_IDENTIFIER
	};
	char				*identifier;
	int					i;

	identifier = get_data(line);
	i = 0;
	while (i < MAX_PARAMETERS)
	{
		if (ft_strcmp(identifier, identifiers[i]) == 0)
		{
			ft_strcpy(line -> identifier, identifier);
			line -> identifier_id = i;
			break ;
		}
		i++;
	}
	return (line -> identifier[0] != 0 && line -> size > line -> skipped + 1);
}

bool	parse_line(t_content_file *node, t_figure *infos)
{
	static const int	jump[MAX_PARAMETERS] = {0, 0, sizeof(t_light),
		sizeof(t_sphere), sizeof(t_plan), sizeof(t_cylinder)};
	static int			times[MAX_PARAMETERS] = {0, 0, -1, -1, -1, -1};
	void *const			addrs[MAX_PARAMETERS] = {
		& infos -> ambient_light,
		& infos -> camera,
		& infos -> light,
		& infos -> sphere,
		& infos -> plan,
		& infos -> cylinder,
	};
	int					id;

	if (! get_index_from_identifier(& node -> line))
		return (false);
	id = node -> line.identifier_id;
	times[id]++;
	if (times[0] > 1 || times[1] > 1 || times[id] > 99)
		return (false);
	ft_strcpy((char *)addrs[id] + (times[id] * jump[id]),
		node -> line.identifier);
	return (fill_struct(& node -> line, addrs[id] + (times[id] * jump[id]))
		&& node -> line.size == node -> line.skipped);
}
