/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:22:26 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 17:47:24 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_line_height(t_camera *c)
{
	c->line_height = (int)(SCREEN_HEIGHT / c->perp_wall_dist);
	c->draw_start = -c->line_height / 2 + SCREEN_HEIGHT / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	if (c->draw_start >= SCREEN_HEIGHT)
		c->draw_start = SCREEN_HEIGHT - 1;
	c->draw_end = c->line_height / 2 + SCREEN_HEIGHT / 2;
	if (c->draw_end >= SCREEN_HEIGHT)
		c->draw_end = SCREEN_HEIGHT - 1;
	if (c->draw_end < 0)
		c->draw_end = 0;
}

void	calcul_perp_wall_dist(t_player *p, t_camera *c)
{
	if (c->side == 0)
		c->perp_wall_dist = \
			(c->map_x - p->x + (1 - c->step_x) / 2) \
			/ c->ray_dir_x;
	else
		c->perp_wall_dist = \
			(c->map_y - p->y + (1 - c->step_y) / 2) \
			/ c->ray_dir_y;
}

static void	select_nwse_texture(t_player *p, t_camera *c)
{
	if (c->side == 0)
	{
		if (c->map_x > p->x)
			c->texture_nr = 3;
		else
			c->texture_nr = 2;
	}
	else
	{
		if (c->map_y > p->y)
			c->texture_nr = 0;
		else
			c->texture_nr = 1;
	}
}

void	calcul_dda(t_game *game, t_camera *c)
{
	while (c->hit == 0)
	{
		if (c->side_dist_x < c->side_dist_y)
		{
			c->side_dist_x += c->delta_dist_x;
			c->map_x += c->step_x;
			c->side = 0;
		}
		else
		{
			c->side_dist_y += c->delta_dist_y;
			c->map_y += c->step_y;
			c->side = 1;
		}
		if (game->map->grid[c->map_y][c->map_x] != '0' \
			&& !ft_strchr("NWES", game->map->grid[c->map_y][c->map_x]))
		{
			c->hit = 1;
			select_nwse_texture(game->player, c);
		}
	}
}

void	calcul_step_side_dist(t_player *p, t_camera *c)
{
	if (c->ray_dir_x < 0)
	{
		c->step_x = -1;
		c->side_dist_x = \
			(p->x - c->map_x) * c->delta_dist_x;
	}
	else
	{
		c->step_x = 1;
		c->side_dist_x = \
			(c->map_x + 1.0 - p->x) * c->delta_dist_x;
	}
	if (c->ray_dir_y < 0)
	{
		c->step_y = -1;
		c->side_dist_y = \
			(p->y - c->map_y) * c->delta_dist_y;
	}
	else
	{
		c->step_y = 1;
		c->side_dist_y = \
			(c->map_y + 1.0 - p->y) * c->delta_dist_y;
	}
}
