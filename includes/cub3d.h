/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:01:34 by osarsari          #+#    #+#             */
/*   Updated: 2024/04/04 12:27:03 by osarsari         ###   ########.fr       */
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
# include "../libs/libft/includes/libft.h"
# include "../libs/libft/includes/get_next_line.h"

# define ERROR -1

// Screen resolution
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

// Texture dimensions
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

// Keycodes
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

// Image structure
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	int		**textures;
}			t_img;

// Player structure
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	ms;
	double	rs;
	char	dir;
}			t_player;

// Camera structure
typedef struct s_camera
{
	double	x;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;

	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_nr;
	int		text_x;
}			t_camera;

// Map structure
typedef struct s_map
{
	int		fd;
	int		rows;
	char	**grid;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		ceiling;
	int		f_rgb[3];
	int		c_rgb[3];
}	t_map;

// Game structure
typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			buf[SCREEN_HEIGHT][SCREEN_WIDTH];
	int			re_buf;
	t_map		*map;
	t_img		*img;
	t_player	*player;
	t_camera	*camera;
}				t_game;

//		INIT_CHECKS
int		init_checks(t_game *game, char *map_file);

//		MAP_TYPE_ID
char	*get_type_identifier(t_map *game);
int		init_type_id_from_line(char *line, t_map *game);
int		is_type_id(t_map *game, char **elements);

//		MAP_RGB
int		retrieve_color_rgb(char *colors, t_map *game);

//		MAP_GRID (RETRIEVE THE CHAR **GRID)
int		get_map_grid(t_map *game, char *line);

//		MAP_CHECK (CHECK THE WALLS + CHARS WITHIN MAP)
int		valid_map_line(char **grid);
int		walls_check(char **grid, int rows);
int		map_chars_check(char **grid, t_game *game);

//		MAP_UTILS
int		ft_strcmp(const char *s1, const char *s2);
int		error_msg(char *message);
int		number_of_(char **array);
int		valid_file_extension(char *file_name, char *file_extension);
int		check_missing_type_id_info(t_map *map);

//		INIT_GAME
int		set_player_var(t_game *game, int x, int y);
void	init_buffer(t_game *game);
int		init_game(t_game *game);

//		INIT_GRAPHIC
int		rgb_to_int(int r, int g, int b);
void	set_background_color(t_img *bg_img, t_map *map, int *y, int *x);
void	display_(t_game *game);
int		init_graphics(t_game *game);

//		TEXTURES
int		load_texture(t_game *game);

//		RAYCASTING
void	raycasting(t_game *game);

//		RAYCASTING_CALCUL
void	calcul_line_height(t_camera *c);
void	calcul_perp_wall_dist(t_player *player, t_camera *camera);
void	calcul_dda(t_game *game, t_camera *camera);
void	calcul_step_side_dist(t_player *player, t_camera *camera);

//		RAYCASTING_DRAW
void	calcul_texture_drawing(t_game *game, t_camera *camera, int *x);
void	calcul_line_height(t_camera *camera);

//		KEY_MOVEMENT
void	move_w_s(t_player *player, char **map, int keycode);
void	move_a_d(t_player *player, char **map, int keycode);
void	rotate(t_player *player, t_camera *camera, int keycode);

//		KEY_PRESS
int		key_press(int keycode, t_game *game);

//		FREE
void	free_map_struct(t_map *map);
void	free_texture_array(int **array);
void	free_array(char **array);
void	ft_free_checks(t_game *game);
void	ft_free_game(t_game *game);

#endif