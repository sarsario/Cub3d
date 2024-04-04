/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:26 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 10:50:45 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_map	*init_map_struct(t_game *game)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	game->map = map;
	map->fd = ERROR;
	map->rows = 0;
	map->grid = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->floor = 0;
	map->ceiling = 0;
	map->f_rgb[0] = -1;
	map->f_rgb[1] = -1;
	map->f_rgb[2] = -1;
	map->c_rgb[0] = -1;
	map->c_rgb[1] = -1;
	map->c_rgb[2] = -1;
	return (map);
}

int	init_checks(t_game *game, char *map_file)
{
	char	*line;
	t_map	*map;

	map = init_map_struct(game);
	if (!map)
		return (0);
	map->fd = open(map_file, O_RDONLY);
	if (map->fd == ERROR)
		return (error_msg("failure to open the scene description file"));
	if (!valid_file_extension(map_file, ".cub"))
		return (error_msg("this is not a valid .cub file"));
	line = get_type_identifier(map);
	if (!line)
		return (0);
	if (!get_map_grid(map, line))
		return (error_msg("missing/duplicate map"));
	if (!walls_check(map->grid, map->rows) || !valid_map_line(map->grid))
		return (error_msg("issue with the map walls"));
	if (!map_chars_check(map->grid, game))
		return (0);
	return (1);
}
