/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_epic_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:12:46 by esnowbal          #+#    #+#             */
/*   Updated: 2020/10/28 19:33:36 by esnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	countres(double xx, double yy)
{
	if (fabs(xx) == 0)
		return (fabs(yy) + 0.000001);
	else if (fabs(yy) == 0)
		return (fabs(xx) + 0.000001);
	else if (fabs(xx) < fabs(yy))
		return (fabs(xx) + 0.000001);
	else
		return (fabs(yy) + 0.000001);
}

static double	avoid_norm(double *yy, double x, double y, double a)
{
	*yy = (y - (int)y) / (sin(correctangle(a)));
	return (((int)x - x + 1) / cos(a));
}

void			epic_raycasting(double *c, double x, double y, double a)
{
	double xx;
	double yy;
	double result;

	if ((a > 0 && a <= M_PI_2) || (a > 0 + 2 * M_PI && a <= M_PI_2 + 2 * M_PI))
	{
		xx = (((int)x - x + 1) / cos(a));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a > M_PI_2 && a < M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(a)));
		yy = (((int)y - y + 1) / sin(a));
	}
	else if (a <= -M_PI_2 + 2 * M_PI && a >= M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(a)));
		yy = (y - (int)y) / (sin(correctangle(a)));
	}
	else
		xx = avoid_norm(&yy, x, y, a);
	result = countres(xx, yy);
	*c = *c + result;
}
