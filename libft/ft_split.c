/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:07:24 by esnowbal          #+#    #+#             */
/*   Updated: 2020/09/12 20:04:59 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_it(char **str, int i)
{
	while (i-- != 0)
	{
		free(str[i]);
	}
	free(str);
}

static	size_t	word_num(char const *s, char c)
{
	int i;

	i = 0;
	if (*s == c || *s == '\0')
		i = -1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	return (i);
}

static	size_t	word_l(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static	char	**fill_it(char const *s, char c)
{
	int		word_len;
	int		i;
	char	**res;

	if (!(res = (char**)malloc(sizeof(char*) * (word_num(s, c) + 2))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = word_l(s, c);
			if (!(res[i] = (char*)malloc(sizeof(char) * word_len + 1)))
			{
				free_it(res, i);
				return (NULL);
			}
			ft_strlcpy(res[i++], s, word_len + 1);
			s = s + word_len - 1;
		}
		s++;
	}
	res[i] = 0;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = fill_it(s, c);
	return (res);
}
