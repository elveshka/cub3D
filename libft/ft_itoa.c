/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 04:04:26 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/22 05:37:01 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	fill_it(char *s, int n, size_t i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			s[0] = '-';
			s[1] = '2';
			n = 147483648;
			i++;
		}
		else
		{
			s[0] = '-';
			i++;
			n *= -1;
		}
	}
	while (i-- != 0)
	{
		if (!s[i])
			s[i] = n % 10 + 48;
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		nb;

	nb = n;
	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	if (n > 0)
		res = (char*)ft_calloc(i + 1, sizeof(char));
	else if (n < 0)
		res = (char*)ft_calloc(i + 2, sizeof(char));
	else
	{
		res = (char*)ft_calloc(2, sizeof(char));
		i++;
	}
	if (!res)
		return (NULL);
	fill_it(res, n, i);
	return (res);
}
