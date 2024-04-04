/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:13:59 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 12:05:24 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_pixel(t_img *img, t_pixel *pixel)
{
	char	*dst;

	dst = img->addr + (pixel->y * img->line_len + pixel->x * (img->bpp / 8));
	*(unsigned int *)dst = pixel->color;
}

void	draw_bg(t_img *img, int ceil, int floor)
{
	t_pixel	px;
	int		half_height;

	px.y = 0;
	half_height = SCREEN_HEIGHT / 2;
	while (px.y < half_height)
	{
		px.color = floor;
		if (px.y < half_height)
			px.color = ceil;
		px.x = 0;
		while (px.x < SCREEN_WIDTH)
		{
			draw_pixel(img, &px);
			px.x++;
		}
		px.y++;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		esc(game, 0);
	if (keycode == KEY_W || keycode == KEY_S)
		move_w_s(game->player, game->map, keycode);
	if (keycode == KEY_A || keycode == KEY_D)
		move_a_d(game->player, game->map, keycode);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(game->player, game->camera, keycode);
	mlx_destroy_image(game->mlx, game->img->img);
	game->img->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->img->img == NULL)
	{
		printf("Error: mlx_new_image failed\n");
		esc(game, 1);
	}
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	draw_bg(game->img, CEIL_COLOR, FLOOR_COLOR);
	ray_cast(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}
