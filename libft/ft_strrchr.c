/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:01:51 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/14 20:18:34 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
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
			res = (char*)s;
		s++;
	}
	return (res);
}
