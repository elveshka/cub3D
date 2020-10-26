/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 11:06:15 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/26 08:56:59 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!dest || !src)
		return (dest);
	ret = dest;
	while (n != 0)
	{
		*(char*)dest = *(char*)src;
		dest++;
		src++;
		n--;
	}
	return (ret);
}
