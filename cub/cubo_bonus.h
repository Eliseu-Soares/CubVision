/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:34:30 by sgaspar           #+#    #+#             */
/*   Updated: 2026/09/14 16:07:40 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef CUBO_BONUS_H
# define CUBO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include "./minilibx-linux/mlx.h"
# include "./lib/libft/get_next_line.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h"
# include "./src/utils/utils_bonus.h"
# include "config_bonus.h"
# define ERR_FILE_NOT_CUB "Error\nNot a .cub file\n"
# define ERR_FILE_NOT_XPM "Error\nOne or more invalid extensions for \
texture were found\n"
# define INVALID_FILE "Error\nInvalid file\n"
# define ERR_CUB_USEGE "Error\nUsage: ./cub3d <path/to/map.cub>\n"
# define EMPTY_FILE "Error\nThe file is empty\n"
# define NO_PERMISSION "Error\nFile without permission\n"
# define NO_EXISTS "Error\nFile does not exist\n"
# define TEXTURE_NO_EXISTS "Error\nOne or more textures does not exist\n"
# define INVALID_INDETIFIER "Error\nOne or more invalid indentifier\n" 
# define INVALID_TEXTURE_PATH "Error\nInvalid texture path\n"
# define INVALID_COLOR "Error\nInvalid color value\n"
# define INVALID_RANGE "Error\nInvalid range value, valid range is [0...255]\n"
# define NOT_FOUND_TEXTURE "Error\nOne or more texture not found\n"
# define NOT_FOUND_COLOR "Error\nOne or more color not found\n"
# define INVALID_CHARACTER "Error\nInvalid character in map\n"
# define MULTIPLE_PLAYER "Error\nMultiple player positions found in map\n"
# define NO_PLAYER "Error\nPlayer not found in map\n"
# define MORE_TEXTURE "Error\nMore than four textures found\n"
# define MORE_COLOR "Error\nMore than two colors found\n"
# define INVALID_MAP "Error\nInvalid map\n"

enum e_texture
{
	e_N,
	e_S,
	e_E,
	e_W
};

struct s_point
{
	int	start;
	int	end;
};

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**grid;
	int		*floor;
	int		*ceiling;
	int		rows;
	int		cols;
	int		height;
}	t_map;

typedef struct s_file
{
	char	**lines;
	int		count;
}	t_file;

typedef struct s_2d_f
{
	double	x;
	double	y;
}	t_2d_f;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_img;

typedef struct s_texture
{
	t_data_img	data;
	t_vec2		size;
}	t_text2d;



# include <sys/socket.h>
# include <netinet/in.h>

# define UDP_PORT 5000
# define UDP_BUFFER_SIZE 1024
typedef struct s_udp
{
	int					fd;
	struct sockaddr_in	addr;
	char				buffer[UDP_BUFFER_SIZE];
}	t_udp;


void	rotate(t_cubo *cubo, float angle, float speed);
int		key_event(int key, void *parm);
int		mouse_event(int x, int y, void *param);
int		udp_init(t_udp *udp);
int	udp_receive(t_udp *udp);
void	udp_close(t_udp *udp);
int init_udp(t_cubo *cubo);
void	handle_udp_command(t_cubo *cubo, char command);

typedef struct s_cubo
{
	t_data_img	canva;
	t_text2d	texture[4];
	t_file		*file;
	t_udp		udp;
	t_2d_f		player;
	t_2d_f		dir;
	t_2d_f		plane;
	t_2d_f		side_dist;
	t_2d_f		delta_dist;
	t_2d_f		ray_dir;
	t_map		*maps;
	void		*mlx;
	void		*win;
	double		camerax;
	double		perp_wall_dist;
	double		time;
	double		old_time;
	double		frame_time;
	double		speed_rotate;
	t_vec2		map;
	t_vec2		step;
	int			side_rotate;
	int			hit;
	int			side;
	int			color_floor;
	int			color_sky;
	int			updated;
	int			mouse_side_rotate;
	int			udp_side_rotate;
}	t_cubo;

void	move_front_back(t_cubo *cubo, int side);
void	destroy(t_cubo *cubo);
void	draw_to_canva(t_cubo *cubo, int x);
void	print_error(char *msg);
void	print_error_and_free(char *msg, char *path);
void	hz_strcpy(char *s1, char *s2, int n);
void	free_split(char **str);
void	load_map(char *file_path, t_cubo *cubo);
void	load_texture_data(t_cubo *cubo);
void	init_windows(t_cubo *cubo);
void	draw_minimap(t_cubo *cubo);
bool	parse_file(t_cubo *cub);
bool	primary_filter_char(char **lines);
bool	is_just_space_line(char *line);
bool	arg_check(char *str);
bool	arg_validation(char *arg);
bool	point(char *str);
bool	is_invalid_map(char **map);
bool	is_empty_line(char *line);
bool	parse_and_load_colors(t_cubo *cub, char **lines, int i);
bool	strncmp_with_spaces(char *raw_path, char *indetifier);
bool	validation_extension(char *str, char *extension);
bool	is_empty_file_and_valid_file(char *file, int is_texture);
bool	parse_and_load_texture2(char *raw_path, t_cubo *cub);
bool	parse_and_load_texture(t_cubo *cub, char **lines, int i);
bool	parse_and_load_texture2(char *raw_path, t_cubo *cub);
bool	parse_and_load_texture(t_cubo *cub, char **lines, int i);
bool	is_map_line(char *line);
bool	validate_texture(t_cubo *cubo);
bool	all_configs_loaded(t_cubo *cub);
bool	flood_fill(t_cubo *cub, char **map, int x, int y);
bool	validate_color(t_cubo *cub);
bool	check_char_invalid_in_map(char **map);
bool	is_map_invalid(char **new_map);
bool	ft_isspace(char c);
bool	get_floor(char *raw_colors, t_cubo *cub, char *colors);
bool	is_invalid_space(char **map);
bool	found_x_char(char **map);
bool	get_floor(char *raw_colors, t_cubo *cub, char *colors);
bool	flood_fill_space(int height, char **map, int x, int y);
char	*get_xtension(char *str);
char	*get_path_texture(char *raw_path);
char	**new_map(char **lines, int j);
char	**fill_new_map(char **lines, int j);
char	*get_value_color(char *raw_color);
int		*array_chr_to_array_int(char *str_color);
int		parse_colors_and_texture(t_cubo *cub, char **lines);
int		skiping_to_space_diff(char *line);
int		init_cubo(t_cubo *cubo);
int		pos_xtension(char *str);
int		skiping_to_space_diff(char *line);
int		get_max_line(char **lines);
int		get_height_map(char **map);

#endif
