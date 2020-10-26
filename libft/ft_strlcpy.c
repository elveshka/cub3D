/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:29:10 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/22 01:15:22 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (!src)
	{
		dst = (char*)src;
		return (0);
	}
	src_len = ft_strlen(src);
	if (!dst)
		return (src_len);
	if (size > src_len + 1)
		size = src_len + 1;
	if (size != 0)
		ft_memcpy(dst, src, size - 1);
	dst[size - 1] = '\0';
	return (src_len);
}
