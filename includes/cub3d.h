/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:18:44 by osarsari          #+#    #+#             */
/*   Updated: 2024/02/28 10:25:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# include "../mlx/mlx.h"

// Screen resolution
# define MWIDTH 24
# define MHEIGHT 24
# define SWIDTH 640
# define SHEIGHT 480

// Image struct
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Point struct
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// Pixel struct
typedef struct s_pixel
{
	t_point	point;
	int		color;
}			t_pixel;

// utils
void	draw_pixel(t_img *img, t_pixel *pixel);
void	draw_line(t_img *img, t_point *a, t_point *b, int color);

#endif