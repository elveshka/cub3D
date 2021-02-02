/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:19:52 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 23:18:50 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	atoi_double_overflow(const char *str)
{
	int size;

	size = 0;
	while (*str >= 48 && *str <= 57)
	{
		str++;
		size++;
		if (size > 19)
			return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int res;
	int	less0;

	res = 0;
	less0 = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			less0 = -1;
		str++;
	}
	if (atoi_double_overflow(str) == 1 && less0 == 1)
		return (-1);
	if (atoi_double_overflow(str) == 1 && less0 == -1)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * less0);
}
