/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 17:44:56 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	error_msg(char *message)
{
	printf("\033[0;31m" "Error\n\t%s\n" "\033[0m", message);
	return (0);
}

int	number_of_(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	valid_file_extension(char *file_name, char *file_extension)
{
	int	i;
	int	j;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	j = 0;
	while (file_extension[j] && file_name[i + j] == file_extension[j])
		j++;
	if (j == 4 && file_name[i + j] == '\0')
		return (1);
	return (0);
}

int	check_missing_type_id_info(t_map *map)
{
	if (!map->no_path || !map->so_path || !map->ea_path || !map->we_path)
		return (1);
	if (map->floor != 1 || map->ceiling != 1)
		return (1);
	return (0);
}
