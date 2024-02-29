/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:04:11 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/29 12:00:24 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	delta_calc(t_delta *delta, t_point *start, double angle)
{
	delta->dx = cos(angle);
	delta->dy = sin(angle);
	delta->sx = -1;
	delta->sy = -1;
	if (start->x < start->x + delta->dx)
		delta->sx = 1;
	if (start->y < start->y + delta->dy)
		delta->sy = 1;
	delta->err = -delta->dy / 2;
	if (delta->dx > delta->dy)
		delta->err = delta->dx / 2;
}

void	ray_cast(t_point *start, double angle, int **map, t_point *end)
{
	t_delta	delta;

	end->x = start->x;
	end->y = start->y;
	delta_calc(&delta, end, angle);
	while (map[end->y][end->x] != 1)
	{
		delta.e2 = delta.err;
		if (delta.e2 > -delta.dx)
		{
			delta.err -= delta.dy;
			end->x += delta.sx;
		}
		if (delta.e2 < delta.dy)
		{
			delta.err += delta.dx;
			end->y += delta.sy;
		}
	}
}
