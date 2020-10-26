/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:11:41 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/28 15:12:10 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		s2_len;
	size_t		i;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char*)s1);
	while (len > 0 && *s1 != '\0')
	{
		i = 0;
		while (s2[i] && len >= s2_len && *(s1 + i) == s2[i])
		{
			i++;
		}
		if (i == s2_len)
			return ((char*)s1);
		s1++;
		len--;
	}
	return (NULL);
}
