/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:58:41 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 18:07:59 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	texture_drawing_loop(t_game *game, t_camera *c, int *x)
{
	double	step;
	double	text_pos;
	int		text_y;
	int		color;
	int		y;

	step = 1.0 * TEXTURE_HEIGHT / game->camera->line_height;
	text_pos = (c->draw_start - SCREEN_HEIGHT \
				/ 2 + c->line_height / 2) * step;
	y = c->draw_start;
	while (y < c->draw_end)
	{
		text_y = (int)text_pos & (TEXTURE_HEIGHT - 1);
		text_pos += step;
		color = game->img->textures[c->texture_nr] \
									[TEXTURE_HEIGHT * text_y + c->text_x];
		if (c->side == 1)
			color = (color >> 1) & 8355711;
		game->buf[y][*x] = color;
		game->re_buf = 1;
		y++;
	}
}

void	calcul_texture_drawing(t_game *game, t_camera *c, int *x)
{
	if (c->side == 0)
		c->wall_x = game->player->y + c->perp_wall_dist * c->ray_dir_y;
	else
		c->wall_x = game->player->x + c->perp_wall_dist * c->ray_dir_x;
	c->wall_x -= floor(c->wall_x);
	c->text_x = (int)(c->wall_x * (double)TEXTURE_WIDTH);
	if (c->side == 0 && c->ray_dir_x > 0)
		c->text_x = TEXTURE_WIDTH - c->text_x - 1;
	if (c->side == 1 && c->ray_dir_y < 0)
		c->text_x = TEXTURE_WIDTH - c->text_x - 1;
	texture_drawing_loop(game, c, x);
}
