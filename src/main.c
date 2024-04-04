/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:59:31 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 12:10:21 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
	{
		free(game);
		return (1);
	}
	game->img->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
		&game->img->line_len, &game->img->endian);

	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
	{
		mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
		free(game);
		return (1);
	}
	// Set player position, direction, and fov
	game->player->x = 2.0;
	game->player->y = 2.0;
	game->player->dir_x = 0.0;
	game->player->dir_y = 1.0;
	game->player->ms = 0.1;
	game->player->rs = 0.1;
	// Set the camera plane
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		free(game->player);
		mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
		free(game);
		return (1);
	}
	game->camera->plane_x = -0.66;
	game->camera->plane_y = 0.0;
	// Set the map
	game->map = (int **)malloc(sizeof(int *) * 10);
	if (!game->map)
	{
		free(game->player);
		mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
		free(game->camera);
		free(game);
		return (1);
	}
	int i = 0;
	while (i < 10)
	{
		game->map[i] = (int *)malloc(sizeof(int) * 10);
		if (!game->map[i])
		{
			while (i >= 0)
				free(game->map[i--]);
			free(game->player);
			mlx_destroy_image(game->mlx, game->img->img);
			free(game->img);
			free(game->camera);
			free(game);
			return (1);
		}
		i++;
	}
	int j;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game->map[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 10)
	{
		game->map[i][0] = 1;
		game->map[i][9] = 1;
		i++;
	}
	j = 0;
	while (j < 10)
	{
		game->map[0][j] = 1;
		game->map[9][j] = 1;
		j++;
	}
	game->map[3][4] = 1;
	game->map[3][5] = 1;
	game->map[3][7] = 1;
	game->map[4][4] = 1;
	game->map[4][7] = 1;
	game->map[5][4] = 1;
	game->map[5][7] = 1;
	game->map[6][4] = 1;
	game->map[6][6] = 1;
	game->map[6][7] = 1;

	// Horizon set at half the screen height
	// int	half_height = SCREEN_HEIGHT / 2;

	// Draw the background
	draw_bg(game->img, CEIL_COLOR, FLOOR_COLOR);
	printf("bg drawn\n");
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	// Draw the walls
	// raycast(game->img, game->player->x, game->player->y, game->player->angle, game->map, WALL_COLOR);
	ray_cast(game);
	printf("walls drawn\n");
	// Display the image
	// mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);

	// Hook the key press
	mlx_hook(game->win, 2, 1L << 0, key_press, game);

	// Loop
	mlx_loop(game->mlx);
	return (0);
}
