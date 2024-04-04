/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:04:10 by osarsari          #+#    #+#             */
/*   Updated: 2024/04/03 17:42:30 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_raycast_param(t_game *game, t_camera *c, int x)
{
	c->x = 2 * x / (double)SCREEN_WIDTH - 1;
	c->ray_dir_x = game->player->dir_x + c->plane_x * c->x;
	c->ray_dir_y = game->player->dir_y + c->plane_y * c->x;
	c->map_x = (int)game->player->x;
	c->map_y = (int)game->player->y;
	if (c->ray_dir_x == 0)
		c->delta_dist_x = 1e30;
	else
		c->delta_dist_x = fabs(1 / c->ray_dir_x);
	if (c->ray_dir_y == 0)
		c->delta_dist_y = 1e30;
	else
		c->delta_dist_y = fabs(1 / c->ray_dir_y);
	c->hit = 0;
	c->texture_nr = 0;
}

void	raycasting(t_game *game)
{
	int	x;

	if (game->re_buf == 1)
		init_buffer(game);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		set_raycast_param(game, game->camera, x);
		calcul_step_side_dist(game->player, game->camera);
		calcul_dda(game, game->camera);
		calcul_perp_wall_dist(game->player, game->camera);
		calcul_line_height(game->camera);
		calcul_texture_drawing(game, game->camera, &x);
		x++;
	}
}
