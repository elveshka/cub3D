/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:36:16 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/19 19:56:20 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, ssize_t size)
{
	size_t	res;

	if (size < ft_strlen(dst) + 1)
		return (ft_strlen(src) + size);
	res = ft_strlen(src) + ft_strlen(dst);
	while (*dst && size != 0)
	{
		dst++;
		size--;
	}
	size--;
	if (size > 0)
	{
		while (size != 0 && *src)
		{
			*dst = *src;
			dst++;
			src++;
			size--;
		}
		*dst = '\0';
	}
	return (res);
}
