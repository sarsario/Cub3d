/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:57:45 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/03/25 13:35:39 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_fill_floor_rgb(t_map *map, char **rgb_values)
{
	int	i;

	i = 0;
	if (map->floor && map->f_rgb[0] == -1 && map->f_rgb[1] == -1 \
			&& map->f_rgb[2] == -1)
	{
		while (i < 3)
		{
			if (ft_atoi(rgb_values[i]) < 0 || ft_atoi(rgb_values[i]) > 255)
				return (error_msg("floor rgb not within range [0, 255]"));
			map->f_rgb[i] = ft_atoi(rgb_values[i]);
			i++;
		}
	}
	return (1);
}

static int	check_fill_ceiling_rgb(t_map *map, char **rgb_values)
{
	int	i;

	i = 0;
	if (map->ceiling && map->c_rgb[0] == -1 && map->c_rgb[1] == -1 \
			&& map->c_rgb[2] == -1)
	{
		while (i < 3)
		{
			if (ft_atoi(rgb_values[i]) < 0 || ft_atoi(rgb_values[i]) > 255)
				return (error_msg("ceiling rgb not within range [0, 255]"));
			map->c_rgb[i] = ft_atoi(rgb_values[i]);
			i++;
		}
	}
	return (1);
}

static int	check_rgb_digits(char **rgb_values)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_values[i])
	{
		j = 0;
		while (rgb_values[i][j] && rgb_values[i][j] != '\n')
		{
			if (!ft_isdigit(rgb_values[i][j]))
				return (error_msg("negative or non digit(s) in rgb values."));
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_format_rgb_str(char *rgb_str)
{
	int	comma;
	int	i;

	if (!rgb_str)
		return (0);
	i = 0;
	comma = 0;
	while (rgb_str && rgb_str[i])
	{
		if (rgb_str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (error_msg("invalid rgb format/missing rgb value(s)"));
	return (1);
}

int	retrieve_color_rgb(char *rgb_str, t_map *map)
{
	char	**rgb_values;

	if (!check_format_rgb_str(rgb_str))
		return (2);
	rgb_values = ft_split(rgb_str, ',');
	if (!rgb_values)
		return (-1);
	if (number_of_(rgb_values) != 3 || !check_rgb_digits(rgb_values))
	{
		free_array(rgb_values);
		return (2);
	}
	if ((map->floor && !check_fill_floor_rgb(map, rgb_values)) \
		|| (map->ceiling && !check_fill_ceiling_rgb(map, rgb_values)))
	{
		free_array(rgb_values);
		return (2);
	}
	free_array(rgb_values);
	return (1);
}
