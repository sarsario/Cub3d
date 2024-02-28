/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:04:11 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/28 19:41:14 by osarsari         ###   ########.fr       */
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

/*
** The purpose of the ray casting in this project is to determine the
** coordinates p1 and p2 of the obstacles. Still not sure if it is p1 and p2 on
** the same line or p1 and p2 on the same column. With p1 and p2, we can then
** draw a line between them using the draw_line function.
** Concerns: draw_line draws one color. What about textures?
*/

// Actually, same as draw_line, but while loop condition ends when we reach
// a wall in the map instead of reaching the second point
void	ray_cast(t_point *start, double angle, int **map)
{
	// From point p and angle, we can determine dx and dy
	t_point	p;
	t_delta	delta;
	p.x = start->x;
	p.y = start->y;
	delta_calc(&delta, &p, angle);
}
