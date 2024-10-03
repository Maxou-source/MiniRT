/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:14:43 by ooxn              #+#    #+#             */
/*   Updated: 2023/09/27 16:37:04 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_strncat(char *dst, const char *src, size_t nb)
{
	char	*start;

	start = dst;
	while (*start)
		start++;
	while (*src && nb-- > 0)
		*start++ = *src++;
	*start = 0;
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	n;
	size_t	i;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	n = dstsize;
	i = 0;
	if (dstsize > 0)
	{
		while (dst[i] && dstsize > 0)
		{
			i++;
			dstsize--;
		}
		if (dstsize == 0)
			return (n + len_src);
		ft_strncat(dst, src, dstsize - 1);
	}
	return (len_src + len_dst);
}
