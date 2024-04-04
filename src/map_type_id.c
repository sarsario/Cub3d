/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_type_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:56:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 11:36:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	all_valid_type_id(t_map *map, char *line, int *ret)
{
	if (!line)
		return (error_msg("EOF: info missing in scene description file"));
	if (*ret == ERROR)
	{
		free(line);
		return (error_msg("malloc failure"));
	}
	if (*ret == 0 && (!map->no_path || !map->so_path || !map->ea_path \
		|| !map->we_path))
	{
		free(line);
		return (error_msg("duplicates/invalid/missing path(s) to texture"));
	}
	if ((*ret == 0 && (map->floor != 1 || map->ceiling != 1)) || *ret == 2)
	{
		free(line);
		if (*ret == 2)
			return (0);
		return (error_msg("duplicates/invalid/missing floor and/or ceiling"));
	}
	return (1);
}

int	is_type_id(t_map *map, char **elements)
{
	int	ret;

	ret = 1;
	if (!map->no_path && ft_strcmp(elements[0], "NO") == 0)
		map->no_path = elements[1];
	else if (!map->so_path && ft_strcmp(elements[0], "SO") == 0)
		map->so_path = elements[1];
	else if (!map->ea_path && ft_strcmp(elements[0], "EA") == 0)
		map->ea_path = elements[1];
	else if (!map->we_path && ft_strcmp(elements[0], "WE") == 0)
		map->we_path = elements[1];
	else if (ft_strcmp(elements[0], "F") == 0)
		map->floor++;
	else if (ft_strcmp(elements[0], "C") == 0)
		map->ceiling++;
	else
		return (0);
	if ((map->floor && map->f_rgb[0] == -1 && map->f_rgb[1] == -1 \
			&& map->f_rgb[2] == -1) \
		|| (map->ceiling && map->c_rgb[0] == -1 && map->c_rgb[1] == -1 \
			&& map->c_rgb[2] == -1))
		ret = retrieve_color_rgb(elements[1], map);
	if (ret != 1)
		return (ret);
	return (1);
}

static int	check_split_elements(char **elements, t_map *map)
{
	int	ret;

	if (number_of_(elements) != 2)
	{
		free_array(elements);
		if (check_missing_type_id_info(map))
			return (0);
		return (3);
	}
	ret = is_type_id(map, elements);
	if (ret != 1)
	{
		if (map->floor > 1 || map->ceiling > 1)
			return (2);
		return (ret);
	}
	free(elements[0]);
	free(elements);
	return (1);
}

int	init_type_id_from_line(char *line, t_map *map)
{
	char	**elements;
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	str = ft_substr(line, 0, i);
	if (!str)
		return (-1);
	elements = ft_split(str, ' ');
	if (!elements)
		return (-1);
	free(str);
	return (check_split_elements(elements, map));
}

/*
	return from init_type_id_from_line:
	-1	: malloc failure
	0	: this is not a valid type id: faulty line or duplicate
	1	: everything is ok - continue reading from the file
	2	: rgb value error
	3	: this a line from the map grid
*/

char	*get_type_identifier(t_map *game)
{
	char	*line;
	int		ret;

	ret = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		ret = init_type_id_from_line(line, game);
		if (ret != 1)
			break ;
	}
	if (!all_valid_type_id(game, line, &ret))
		return (NULL);
	return (line);
}
