/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:08:00 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 11:16:36 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_bresenham(t_bresenham *bresenham, t_point *p0, t_point *p1)
{
	bresenham->dx = abs(p1->x - p0->x);
	bresenham->dy = abs(p1->y - p0->y);
	bresenham->sx = 1;
	bresenham->sy = 1;
	bresenham->err = bresenham->dx / 2;
	if (p0->x >= p1->x)
		bresenham->sx = -1;
	if (p0->y >= p1->y)
		bresenham->sy = -1;
	if (bresenham->dx <= bresenham->dy)
		bresenham->err = -bresenham->dy / 2;
}

void	draw_line(t_img *img, t_point *p0, t_point *p1, int color)
{
	t_bresenham	data;
	t_pixel		px;

	px.x = p0->x;
	px.y = p0->y;
	px.color = color;
	init_bresenham(&data, p0, p1);
	while (px.x != p1->x || px.y != p1->y)
	{
		draw_pixel(img, &px);
		data.e2 = data.err;
		if (data.e2 > -data.dx)
		{
			data.err -= data.dy;
			px.x += data.sx;
		}
		if (data.e2 < data.dy)
		{
			data.err += data.dx;
			px.y += data.sy;
		}
	}
	draw_pixel(img, &px);
}
