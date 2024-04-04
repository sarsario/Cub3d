/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:52:21 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 16:16:07 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_background_color(t_img *bg_img, t_map *map, int *y, int *x)
{
	int	color;
	int	px;

	if (*y < SCREEN_HEIGHT / 2)
		color = map->ceiling;
	else
		color = map->floor;
	px = (*y * bg_img->line_len) + (*x * 4);
	bg_img->addr[px + 0] = (color) & 0xFF;
	bg_img->addr[px + 1] = (color >> 8) & 0xFF;
	bg_img->addr[px + 2] = (color >> 16) & 0xFF;
	bg_img->addr[px + 3] = (color >> 24);
}

void	display_(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (game->buf[y][x])
				game->img->data[y * SCREEN_WIDTH + x] = game->buf[y][x];
			else
				set_background_color(game->img, game->map, &y, &x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

int	init_graphics(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		return (0);
	if (!load_texture(game))
		return (0);
	game->img->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img->img)
		return (0);
	game->img->data = (int *)mlx_get_data_addr(game->img->img, &game->img->bpp, \
						&game->img->line_len, &game->img->endian);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp, \
						&game->img->line_len, &game->img->endian);
	game->map->floor = rgb_to_int(game->map->f_rgb[0], game->map->f_rgb[1], \
						game->map->f_rgb[2]);
	game->map->ceiling = rgb_to_int(game->map->c_rgb[0], game->map->c_rgb[1], \
						game->map->c_rgb[2]);
	raycasting(game);
	display_(game);
	return (1);
}
