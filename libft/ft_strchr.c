/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:40:05 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/14 20:18:13 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
		{
			s++;
		}
		return ((char*)s);
	}
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
