/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 03:33:57 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/23 03:41:19 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		num;

	num = 0;
	if (!lst)
		return (num);
	else
	{
		num = 1;
		node = lst;
		while (node->next)
		{
			num++;
			node = node->next;
		}
	}
	return (num);
}
