/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:52:48 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 11:15:08 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	fill_texture_array(t_game *game, int *texture, \
								char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(game->mlx, path, \
				&img->width, &img->height);
	if (!img->img)
		return (0);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
				&img->line_len, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, game->img->img);
	return (1);
}

static int	set_textures(t_game *game)
{
	t_img	*img;

	img = game->img;
	if (!fill_texture_array(game, img->textures[0], game->map->no_path, img))
		return (error_msg("NO texture file retrieval issue"));
	if (!fill_texture_array(game, img->textures[1], game->map->so_path, img))
		return (error_msg("SO texture file retrieval issue"));
	if (!fill_texture_array(game, img->textures[2], game->map->ea_path, img))
		return (error_msg("EA texture file retrieval issue"));
	if (!fill_texture_array(game, img->textures[3], game->map->we_path, img))
		return (error_msg("WE texture file retrieval issue"));
	return (1);
}

int	load_texture(t_game *game)
{
	int	i;
	int	j;

	game->img->textures = (int **)malloc(sizeof(int *) * 4);
	if (!game->img->textures)
		return (0);
	i = 0;
	while (i < 4)
	{
		game->img->textures[i] = \
				malloc(sizeof(int) * (TEXTURE_HEIGHT * TEXTURE_WIDTH));
		if (!game->img->textures[i])
			return (0);
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
			game->img->textures[i][j++] = 0;
		i++;
	}
	if (!set_textures(game))
		return (0);
	return (1);
}
