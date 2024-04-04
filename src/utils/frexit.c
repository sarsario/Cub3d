/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:21:22 by osarsari          #+#    #+#             */
/*   Updated: 2024/03/12 11:38:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	esc(t_game *game, int status)
{
	mlx_destroy_image(game->mlx, game->img->img);
	free(game->img);
	free(game->player);
	free(game->camera);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(status);
}
