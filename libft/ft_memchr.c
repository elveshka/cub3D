/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:35:00 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/24 20:58:37 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t n)
{
	unsigned char c;

	c = chr;
	while (n != 0)
	{
		if (*(unsigned char*)str == c)
			return ((void*)str);
		str++;
		n--;
	}
	return (NULL);
}
