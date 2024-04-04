/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 17:09:42 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	allocate_rows(t_map *map, char *line)
{
	char	**temp;
	int		i;

	map->rows++;
	temp = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (!temp)
		return (0);
	temp[map->rows] = 0;
	i = 0;
	while (i < (map->rows - 1))
	{
		temp[i] = map->grid[i];
		i++;
	}
	temp[i] = line;
	if (map->grid)
		free(map->grid);
	map->grid = temp;
	return (1);
}

int	get_map_grid(t_map *map, char *line)
{
	while (1)
	{
		if (!allocate_rows(map, line))
		{
			if (map->grid)
			{
				free_array(map->grid);
				map->grid = NULL;
			}
			break ;
		}
		line = get_next_line(map->fd);
		if (!line || line[0] == '\n')
			break ;
	}
	if (!line && !map->grid)
		return (0);
	if (!map->grid)
		return (0);
	while (line && line[0] == '\n')
		line = get_next_line(map->fd);
	if (line && line[0] != '\n')
		return (0);
	close(map->fd);
	return (1);
}
