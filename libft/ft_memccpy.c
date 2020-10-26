/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 12:38:21 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/28 08:31:28 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char uc;

	uc = c;
	if (!dest || !src)
		return (NULL);
	while (n != 0)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		if (*(unsigned char*)src == uc)
			return (dest + 1);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
