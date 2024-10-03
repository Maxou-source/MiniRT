/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:51:32 by mparisse          #+#    #+#             */
/*   Updated: 2023/09/22 13:45:05 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	set_rgb(const char **s, int *color)
{
	while (ft_isdigit(**s))
	{
		*color = (*color * 10) + (**s) - '0';
		(*s)++;
		if (*color > 255)
			return (false);
	}
	return (true);
}

bool	set_clr(const char *s, int *const ptr, t_line *const line, bool add)
{
	const char	*temp = s;
	int			nbcommai[3];

	nbcommai[2] = 0;
	nbcommai[0] = -1;
	nbcommai[1] = 0;
	while (*s)
	{
		nbcommai[0] = 0;
		if (!set_rgb(&s, &nbcommai[0]))
			return (false);
		nbcommai[1] += *s == ',';
		if (nbcommai[2] != 2 && *s != ',')
			return (false);
		*(ptr + nbcommai[2]++) = nbcommai[0];
		if (!*s || *s == ' ')
			break ;
		s++;
	}
	if (add)
		line -> skipped += (s - temp) + 1;
	return (nbcommai[0] != -1 && nbcommai[1] == 2);
}

char	*set_vector(char *s, float *const ptr)
{
	const size_t	size = ft_strlen(s);
	size_t			act_size;
	char			*find;
	int				i;

	i = 0;
	while (i < 3)
	{
		find = ft_strchr(s, ',');
		if (!find && i != 2)
			return (NULL);
		if (i != 2)
			*find = 0;
		*(ptr + i) = atof(s);
		act_size = ft_strlen(s);
		if (size > act_size + 1)
			s += act_size + 1;
		else
			return (NULL);
		i++;
	}
	return (s);
}
