/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:52:54 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 04:45:29 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# define TILE_SIZE 64
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MAX_RAY_DISTANCE 1000

typedef struct s_color
{
	int	blue;
	int	green;
	int	red;
}	t_colors;

typedef struct s_indice
{
	char		*no_stock;
	char		*we_stock;
	char		*so_stock;
	char		*ea_stock;
	int			no_indice;
	int			we_indice;
	int			so_indice;
	int			ea_indice;
	t_colors	*ciel;
	int			ciel_indice;
	int			floor_indice;
	t_colors	*floor;
	int			begin_line;
	int			player_indice;
	char		player;
}	t_incice;

typedef struct s_param
{
	int		lines_numbers;
	char	*name;
	char	**maps;
	char	**only_maps;
}	t_param;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	int		lines_numbers;
	char	**map_copy;
	double	fov;
	int		wide;
	int		i;
	int		j;
	double	ray_angle;
}	t_player;

typedef struct s_Mytexture{
	void		*image_ptr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_Mytexture;

typedef struct s_cub
{
	t_incice	*indices;
	t_param		*params;
	t_player	*player;
	int			n;
	int			j;
	int			a;
	int			b;
	int			c;
	t_Mytexture	images[4];
}	t_cub;

typedef struct s_raycast
{
	double	distance;
	int		top_position;
	int		bottom_position;
	double	ray_x;
	double	ray_y;
	int		flag;
	int		map_x;
	int		map_y;
	double	ray_dist_x;
	double	ray_dist_y;
	int		step_x;
	int		step_y;
	double	view_angle;
	double	c_distance;
	double	w_h;
	double	m_w;
	int		color;
	int		which;
	t_cub	*cub;
}	t_raycast;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_cub		*cub;
	t_player	*player;
}	t_data;

typedef struct s_loop_data
{
	t_data		*img;
	t_player	*player;
}	t_loop_data;

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);
char			*ft_substr(char *s, int start, int len);
char			*ft_strdup(char *s1);
int				ft_putchar(char c);
void			ft_directions_init(t_cub *cub);
void			directions_details(t_cub *cub);
void			west_ver(char *str, t_cub *cub);
void			south_ver(char *str, t_cub *cub);
void			east_ver(char *str, t_cub *cub);
void			nord_ver(char *str, t_cub *cub);
void			west_var_exist(char *str);
void			south_var_exist(char *str);
void			nord_var_exist(char *str);
void			east_var_exist(char *str);
void			east_store(char *str, t_cub *cub);
void			south_store(char *str, t_cub *cub);
void			nord_store(char *str, t_cub *cub);
void			west_store(char *str, t_cub *cub);
int				w_len(char *str);
void			check_direction_nature(char *str, t_cub *cub);
void			colors_stock(t_cub *cub);
char			**ft_split(char *s, char c);
void			red_floor_split(char *str, t_cub *cub);
void			green_floor_split(char *str, t_cub *cub);
void			blue_floor_split(char *str, t_cub *cub);
void			red_ciel_split(char *str, t_cub *cub);
void			green_ciel_split(char *str, t_cub *cub);
void			blue_ciel_split(char *str, t_cub *cub);
void			double_free(char **str);
int				double_lenght(char **str);
int				number_finder(char *str);
int				comma_finder(char *str);
void			maps_working(t_cub *cub);
void			first_one(t_cub *cub);
void			last_one(t_cub *cub);
void			first_wall(t_cub *cub);
void			last_wall(t_cub *cub);
void			first_line_detecte(t_cub *cub, int i);
int				ciel_detecte(t_cub *cub, int i, int j);
void			rgb_call_function(t_cub *cub, int i, int n);
void			colors_check(t_cub *cub);
int				last_helpful_function(t_cub *cub, int i, int j);
void			player_param(t_cub *cub);
void			space_checking(t_cub *cub);
void			global_error(void);
void			ft_init(t_cub *cub);
int				ft_atoi(const char *str);
int				number_check(char *nb);
int				down_check(int i, t_cub *cub, int j);
int				up_check(int i, t_cub *cub, int j);
void			ft_last_free(t_cub *cub);
void			verification_char(char **map);
char			**real_maps_stock(t_cub *cub);
void			second_last_function(t_cub *cub, int i, int *j);
void			after_line(t_cub *cub);
void			player_env(t_cub *cub);
void			after_line_down(t_cub *cub);
void			space_error(void);
char			*ft_itoa(int n);
void			baybay(t_cub *cub, int i, int j);
void			textures(t_cub *cub, t_data *img);
void			main_screen(t_cub *cub);
void			set_player_position(t_player *player, char **map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				update_screen(void *param);
int				key_press_hook(int keycode, t_player *player);
int				calculate_wide(char **map);
int				calculate_lines(char **map);
void			draw_3d(t_data *img, t_player *player, t_cub *cub);
void			initialize_ray(t_raycast *ray_data, double ray_x,
					double ray_y, double ray_angle);
void			update_ray_data(t_raycast *ray_data, double ray_angle);
t_raycast		cast_ray(t_player *player, double ray_angle, char **map);
void			move_player(t_player *player, double dx,
					double dy, char **map);
unsigned int	which_color(t_cub *cub, int i, int x, int y);
void			render_sky(t_data *img, int x, int top_position, t_cub *cub);
void			render_land(t_data *img, int x,
					int bottom_position, t_cub *cub);
int				create_rgb(int r, int g, int b);
int				differente(int i, t_cub *cub);
int				be_careful(t_cub *cub, int i, int j, int *n);
int				mylasterror(char *t);
char			**to_split(char **tmp, char *str);

#endif