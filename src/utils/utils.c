/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:50:52 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:05 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel(t_img *img, t_pixel *pixel)
{
	char	*dst;

	dst = img->addr + (pixel->point.y * img->line_len
			+ pixel->point.x * (img->bpp / 8));
	*(unsigned int *)dst = pixel->color;
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
