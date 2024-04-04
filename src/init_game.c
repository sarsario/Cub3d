/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:23:15 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 12:04:32 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	set_camera_plane(t_game *game)
{
	int	direction;

	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
		return (0);
	direction = game->player->dir;
	if (direction == 'E' || direction == 'W')
		game->camera->plane_x = 0.0;
	if (direction == 'N' || direction == 'S')
		game->camera->plane_y = 0.0;
	if (direction == 'N')
		game->camera->plane_x = 0.66;
	else if (direction == 'S')
		game->camera->plane_x = -0.66;
	else if (direction == 'E')
		game->camera->plane_y = 0.66;
	if (direction == 'W')
		game->camera->plane_y = -0.66;
	return (1);
}

int	set_player_var(t_game *game, int x, int y)
{
	t_player	*p;

	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	p = game->player;
	if (game->map->grid[y][x] == 'N')
		*p = (t_player){x + 0.5, y + 0.5, 0, -1, 0.11, 0.11, 'N'};
	else if (game->map->grid[y][x] == 'S')
		*p = (t_player){x + 0.5, y + 0.5, 0, 1, 0.11, 0.11, 'S'};
	else if (game->map->grid[y][x] == 'E')
		*p = (t_player){x + 0.5, y + 0.5, 1, 0, 0.11, 0.11, 'E'};
	else if (game->map->grid[y][x] == 'W')
		*p = (t_player){x + 0.5, y + 0.5, -1, 0, 0.11, 0.11, 'W'};
	if (!set_camera_plane(game))
		return (0);
	return (1);
}

void	init_buffer(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
			game->buf[i][j++] = 0;
		i++;
	}
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
		return (0);
	init_buffer(game);
	if (!init_graphics(game))
		return (0);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, (void *)exit, 0);
	mlx_loop(game->mlx);
	return (1);
}
