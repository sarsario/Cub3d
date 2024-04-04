/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:16:30 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 17:44:56 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map_struct(t_map *map)
{
	if (map->grid)
		free_array(map->grid);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->fd != ERROR)
		close(map->fd);
}

void	free_texture_array(int **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < 4)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_checks(t_game *game)
{
	if (game->map)
		free_map_struct(game->map);
	if (game->map)
		free(game->map);
	if (game->player)
		free(game->player);
	if (game->camera)
		free(game->camera);
	free(game);
	exit(EXIT_FAILURE);
}

void	ft_free_game(t_game *game)
{
	if (game->map)
		free_map_struct(game->map);
	if (game->img)
	{
		if (game->img->textures)
			free_texture_array((game->img->textures));
		if (game->mlx && game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
	}
	if (game->player)
		free(game->player);
	if (game->camera)
		free(game->camera);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(EXIT_SUCCESS);
}
