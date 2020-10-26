/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:34:55 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/11 16:18:57 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	if (dest < src)
	{
		dest2 = (char*)dest;
		src2 = (char*)src;
		while (n-- != 0)
		{
			*dest2++ = *src2++;
		}
	}
	else if (src < dest)
	{
		dest2 = (char*)dest + n - 1;
		src2 = (char*)src + n - 1;
		while (n-- != 0)
		{
			*dest2-- = *src2--;
		}
	}
	return (dest);
}
