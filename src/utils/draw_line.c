/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:09:46 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/28 14:42:42 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Struct helper containing the values of the Bresenham's line algorithm
typedef struct s_delta
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_delta;

void	delta_calc(t_delta *delta, t_point *a, t_point *b)
{
	delta->dx = abs(b->x - a->x);
	delta->dy = abs(b->y - a->y);
	delta->sx = -1;
	delta->sy = -1;
	if (a->x < b->x)
		delta->sx = 1;
	if (a->y < b->y)
		delta->sy = 1;
	delta->err = -delta->dy / 2;
	if (delta->dx > delta->dy)
		delta->err = delta->dx / 2;
}

/*
** This function draws a line between two points using the Bresenham's line
** algorithm and the draw_pixel function
**
** t_img *img: the image to draw the line on
** t_point *a: the first point
** t_point *b: the second point
** int color: the color of the line (in hexadecimal format 0xRRGGBB)
**
** return: void
*/

void	draw_line(t_img *img, t_point *a, t_point *b, int color)
{
	t_delta	delta;
	t_pixel	pixel;

	pixel.color = color;
	pixel.point.x = a->x;
	pixel.point.y = a->y;
	delta_calc(&delta, a, b);
	while (pixel.point.x != b->x || pixel.point.y != b->y)
	{
		draw_pixel(img, &pixel);
		delta.e2 = delta.err;
		if (delta.e2 > -delta.dx)
		{
			delta.err -= delta.dy;
			pixel.point.x += delta.sx;
		}
		if (delta.e2 < delta.dy)
		{
			delta.err += delta.dx;
			pixel.point.y += delta.sy;
		}
	}
}
