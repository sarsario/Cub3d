/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:44:36 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 10:50:39 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_map_line(char **grid)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (grid[i])
	{
		j = 0;
		len = ft_strlen(grid[i]);
		while (grid[i][j] && grid[i][j] == ' ')
			j++;
		if (grid[i][j] != '1')
			return (0);
		if (grid[i][len - 2] != '1' && grid[i][len - 2] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	walls_check(char **grid, int rows)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(grid[0]);
	while (grid[0][j] && j < len - 2)
	{
		if (grid[0][j] != '1' && grid[0][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	len = ft_strlen(grid[rows - 1]);
	while (grid[rows - 1][j] && j < len - 2)
	{
		if (grid[rows - 1][j] != '1' && grid[rows - 1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

static int	valid_char_around_floor(char **grid, int *i, int *j)
{
	if ((int)ft_strlen(grid[*i + 1]) < *j || (int)ft_strlen(grid[*i - 1]) < *j)
		return (error_msg("invalid char surrounding floor"));
	if (!grid[*i + 1][*j] || !grid[*i - 1][*j] \
			|| !grid[*i][*j + 1] || !grid[*i][*j - 1])
		return (error_msg("invalid char surrounding floor"));
	if (!ft_strchr("10NSEW", grid[*i + 1][*j]))
		return (error_msg("invalid char surrounding floor"));
	if (!ft_strchr("10NSEW", grid[*i - 1][*j]))
		return (error_msg("invalid char surrounding floor"));
	if (!ft_strchr("10NSEW", grid[*i][*j + 1]))
		return (error_msg("invalid char surrounding floor"));
	if (!ft_strchr("10NSEW", grid[*i][*j - 1]))
		return (error_msg("invalid char surrounding floor"));
	return (1);
}

static int	valid_chars_checks(char **grid, char *grid_row, \
									t_game *game, int *i)
{
	int	j;

	j = 0;
	while (grid_row[j] && j < ((int)ft_strlen(grid_row) - 1))
	{
		if (!ft_strchr("10NSEW ", grid_row[j]))
			return (error_msg("unknown char in map"));
		if (ft_strchr("NSEW", grid_row[j]))
			if (!set_player_var(game, j, *i))
				return (0);
		if (grid_row[j] == '0' && !valid_char_around_floor(grid, i, &j))
			return (0);
		j++;
	}
	return (1);
}

int	map_chars_check(char **grid, t_game *game)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (grid[i])
	{
		if (!valid_chars_checks(grid, grid[i], game, &i))
			return (0);
		j = 0;
		while (grid[i][j])
		{
			if (ft_strchr("NSEW", grid[i][j]))
				pos++;
			j++;
		}
		i++;
	}
	if (pos != 1)
		return (error_msg("duplicate or missing player's position"));
	return (1);
}
