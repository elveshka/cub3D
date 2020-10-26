/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:09:06 by esnowbal          #+#    #+#             */
/*   Updated: 2020/08/28 11:51:31 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*skip_set(char const *s, char const *set, int dir)
{
	int		i;
	int		find_c;

	find_c = 1;
	if (dir < 0)
	{
		while (*s)
			s++;
		s--;
	}
	while (find_c != 0 && *s)
	{
		find_c = 0;
		i = 0;
		while (set[i++] != '\0')
			if (*s == set[i - 1])
				find_c = 1;
		s += dir;
	}
	if (!*s)
		return (0);
	s -= dir;
	return ((char*)s);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	res = skip_set(s1, set, 1);
	if (!res)
		return (ft_strdup("", 0));
	s1 = res;
	res = skip_set(s1, set, -1);
	i = 0;
	while (s1 != res--)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	ft_memcpy(res, s1, i + 1);
	res[i + 1] = '\0';
	return (res);
}
