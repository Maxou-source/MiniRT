/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:47:27 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/22 16:00:13 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	update_ptr(t_line *const line)
{
	if (line -> size < line -> skipped)
		return (false);
	line -> content = line -> begin + line -> skipped;
	return (true);
}

bool	parse_ambient_line(t_line *line, void *const ptr)
{
	*(float *)(ptr + sizeof(t_clr) + sizeof(float)) = atof(get_data(line));
	return (update_ptr(line)
		&& set_clr(line -> content, ptr + (LEN_IDENTIFIER + 1), line, true));
}
