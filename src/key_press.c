/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:14 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 16:17:18 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_free_game(game);
	if (keycode == KEY_W || keycode == KEY_S)
		move_w_s(game->player, game->map->grid, keycode);
	if (keycode == KEY_A || keycode == KEY_D)
		move_a_d(game->player, game->map->grid, keycode);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(game->player, game->camera, keycode);
	mlx_clear_window(game->mlx, game->win);
	raycasting(game);
	display_(game);
	return (0);
}
