/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:11:56 by osarsari          #+#    #+#             */
/*   Updated: 2024/04/01 19:06:17 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_w_s(t_player *player, char **map, int keycode)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (keycode == KEY_W)
	{
		move_x = player->x + player->dir_x * player->ms;
		move_y = player->y + player->dir_y * player->ms;
	}
	else if (keycode == KEY_S)
	{
		move_x = player->x - player->dir_x * player->ms;
		move_y = player->y - player->dir_y * player->ms;
	}
	if (map[(int)player->y][(int)move_x] != '1')
		player->x = move_x;
	if (map[(int)move_y][(int)player->x] != '1')
		player->y = move_y;
}

void	move_a_d(t_player *player, char **map, int keycode)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (keycode == KEY_D)
	{
		move_x = player->x - player->dir_y * player->ms;
		move_y = player->y + player->dir_x * player->ms;
	}
	else if (keycode == KEY_A)
	{
		move_x = player->x + player->dir_y * player->ms;
		move_y = player->y - player->dir_x * player->ms;
	}
	if (map[(int)player->y][(int)move_x] != '1')
		player->x = move_x;
	if (map[(int)move_y][(int)player->x] != '1')
		player->y = move_y;
}

static void	rotate_right(t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rs;
	double	sin_rs;

	cos_rs = cos(player->rs);
	sin_rs = sin(player->rs);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos_rs - player->dir_y * sin_rs;
	player->dir_y = old_dir_x * sin_rs + player->dir_y * cos_rs;
	old_plane_x = camera->plane_x;
	camera->plane_x = camera->plane_x * cos_rs - camera->plane_y * sin_rs;
	camera->plane_y = old_plane_x * sin_rs + camera->plane_y * cos_rs;
}

static void	rotate_left(t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rs;
	double	sin_rs;

	cos_rs = cos(-player->rs);
	sin_rs = sin(-player->rs);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos_rs - player->dir_y * sin_rs;
	player->dir_y = old_dir_x * sin_rs + player->dir_y * cos_rs;
	old_plane_x = camera->plane_x;
	camera->plane_x = camera->plane_x * cos_rs - camera->plane_y * sin_rs;
	camera->plane_y = old_plane_x * sin_rs + camera->plane_y * cos_rs;
}

void	rotate(t_player *player, t_camera *camera, int keycode)
{
	if (keycode == 124)
		rotate_right(player, camera);
	if (keycode == 123)
		rotate_left(player, camera);
}
