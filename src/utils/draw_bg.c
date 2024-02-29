/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:22:59 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/29 11:27:26 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_bg(t_img *img, int ceiling, int floor)
{
	t_pixel	pixel;
	int		half_height;

	pixel.point.y = 0;
	half_height = SHEIGHT / 2;
	while (pixel.point.y < SHEIGHT)
	{
		pixel.color = floor;
		if (pixel.point.y < half_height)
			pixel.color = ceiling;
		pixel.point.x = 0;
		while (pixel.point.x < SWIDTH)
		{
			draw_pixel(img, &pixel);
			pixel.point.x++;
		}
		pixel.point.y++;
	}
}
