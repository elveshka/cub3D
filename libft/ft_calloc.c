/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 06:59:35 by esnowbal          #+#    #+#             */
/*   Updated: 2020/09/04 19:03:10 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t cell_size)
{
	void	*res;
	void	*fill;

	if (cell_size != 0)
		if (((count * cell_size) / cell_size) != count)
			return (NULL);
	if (count * cell_size == 0)
		return (malloc(0));
	if (!(res = malloc(cell_size * count)))
		return (NULL);
	fill = res;
	count *= cell_size;
	while (count-- != 0)
	{
		*(char*)fill = 0;
		fill++;
	}
	return (res);
}
