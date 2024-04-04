/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:04:10 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 12:05:09 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_cast(t_game *game)
{
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		game->camera->x = 2 * x / (double)SCREEN_WIDTH - 1;
		game->camera->ray_dir_x = game->player->dir_x + game->camera->plane_x * game->camera->x;
		game->camera->ray_dir_y = game->player->dir_y + game->camera->plane_y * game->camera->x;

		// Which box of the map we're in
		game->camera->map_x = (int)game->player->x;
		game->camera->map_y = (int)game->player->y;

		// Length of ray from one x or y-side to next x or y-side
		game->camera->delta_dist_x = fabs(1 / game->camera->ray_dir_x);
		game->camera->delta_dist_y = fabs(1 / game->camera->ray_dir_y);

		game->camera->hit = 0; // Was there a wall hit?

		// Calculate step and initial side_dist
		if (game->camera->ray_dir_x < 0)
		{
			game->camera->step_x = -1;
			game->camera->side_dist_x = (game->player->x - game->camera->map_x) * game->camera->delta_dist_x;
		}
		else
		{
			game->camera->step_x = 1;
			game->camera->side_dist_x = (game->camera->map_x + 1.0 - game->player->x) * game->camera->delta_dist_x;
		}
		if (game->camera->ray_dir_y < 0)
		{
			game->camera->step_y = -1;
			game->camera->side_dist_y = (game->player->y - game->camera->map_y) * game->camera->delta_dist_y;
		}
		else
		{
			game->camera->step_y = 1;
			game->camera->side_dist_y = (game->camera->map_y + 1.0 - game->player->y) * game->camera->delta_dist_y;
		}

		// Perform DDA
		while (game->camera->hit == 0)
		{
			// Jump to next map square, OR in x-direction, OR in y-direction
			if (game->camera->side_dist_x < game->camera->side_dist_y)
			{
				game->camera->side_dist_x += game->camera->delta_dist_x;
				game->camera->map_x += game->camera->step_x;
				game->camera->side = 0;
			}
			else
			{
				game->camera->side_dist_y += game->camera->delta_dist_y;
				game->camera->map_y += game->camera->step_y;
				game->camera->side = 1;
			}
			// Check if ray has hit a wall
			if (game->map[game->camera->map_x][game->camera->map_y] > 0)
				game->camera->hit = 1;
		}

		// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (game->camera->side == 0)
			game->camera->perp_wall_dist = (game->camera->map_x - game->player->x + (1 - game->camera->step_x) / 2) / game->camera->ray_dir_x;
		else
			game->camera->perp_wall_dist = (game->camera->map_y - game->player->y + (1 - game->camera->step_y) / 2) / game->camera->ray_dir_y;

		// Calculate height of line to draw on screen
		int line_height = (int)(SCREEN_HEIGHT / game->camera->perp_wall_dist);

		// Calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		if (draw_start >= SCREEN_HEIGHT)
			draw_start = SCREEN_HEIGHT - 1;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		if (draw_end < 0)
			draw_end = 0;

		// Draw the pixels of the stripe as a vertical line
		t_point	p0;
		t_point	p1;

		p0.x = x;
		p0.y = draw_start;
		p1.x = x;
		p1.y = draw_end;
		draw_line(game->img, &p0, &p1, WALL_COLOR);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
