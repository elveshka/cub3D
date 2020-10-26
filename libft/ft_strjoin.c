/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:02:31 by esnowbal          #+#    #+#             */
/*   Updated: 2020/09/05 18:30:56 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_s;
	size_t			s1_len;
	size_t			s2_len;
	int				i;

	s2_len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup((char*)s2, s2_len));
	s1_len = ft_strlen(s1);
	if (!(new_s = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		new_s[i] = s1[i];
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		new_s[s1_len + i] = s2[i];
	}
	new_s[s1_len + i] = '\0';
	return (new_s);
}
