/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:29:58 by esnowbal          #+#    #+#             */
/*   Updated: 2020/08/28 11:51:05 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup("", 0));
	if (start + len > s_len)
		len = s_len - start;
	if (!(subs = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(subs, &s[start], len);
	subs[len] = '\0';
	return (subs);
}
