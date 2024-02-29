/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:19:08 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/29 11:38:01 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main()
{
	// Hardcoded map for testing purposes
	/*
	int	map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	*/
	// Hardcoded player position and angle for testing purposes
	// t_point	player = {1, 1};
	// double	angle = 0; // 0 radians is east
	// Hardcoded ceiling, floor and wall colors for testing purposes
	// ceiling = blue, floor = green, wall = red
	int	ceiling = 0x92C7CF;
	int	floor = 0xA1EEBD;
	// int	wall = 0xFF0000;

	t_win	win;
	t_img	img;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, SWIDTH, SHEIGHT, "cub3d");
	img.img = mlx_new_image(win.mlx, SWIDTH, SHEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	// Draw ceiling and floor
	draw_bg(&img, ceiling, floor);

	// What does the player see ?

	// put the image on the window
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
	return (0);
}