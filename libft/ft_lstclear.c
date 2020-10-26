/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 04:59:12 by esnowbal          #+#    #+#             */
/*   Updated: 2020/05/26 13:07:46 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nd;

	if (del)
	{
		while (*lst)
		{
			nd = (*lst)->next;
			del((*lst)->content);
			(*lst)->next = NULL;
			free(*lst);
			*lst = nd;
		}
	}
}
