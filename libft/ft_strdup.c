/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 10:02:47 by esnowbal          #+#    #+#             */
/*   Updated: 2020/09/04 20:33:58 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str, ssize_t n)
{
	char			*res;
	char			*check_mem;

	n = (n == -1) ? ft_strlen(str) : n;
	check_mem = malloc(sizeof(char) * (n + 1));
	if (!(check_mem))
		return (NULL);
	res = check_mem;
	while (n-- > 0)
	{
		*check_mem++ = *(char*)str++;
	}
	*check_mem = '\0';
	return (res);
}
