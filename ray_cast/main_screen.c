/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:05 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 07:59:55 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_close(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	exit(0);
	return (0);
}

int	calculate_wide(char **map)
{
	int	wide;
	int	i;
	int	line_length;

	i = 0;
	wide = 0;
	if (map == NULL || map[0] == NULL)
		return (wide);
	while (map[i] != NULL)
	{
		line_length = 0;
		while (map[i][line_length] != '\0')
			line_length++;
		if (line_length > wide)
			wide = line_length;
		i++;
	}
	return (wide);
}

int	calculate_lines(char **map)
{
	int	lines;

	lines = 0;
	if (map == NULL)
		return (lines);
	while (map[lines] != NULL)
		lines++;
	return (lines);
}

t_player	initialize_player(t_cub *cub)
{
	t_player	player;
	int			lines;
	int			wide;
	int			i;

	i = 0;
	lines = calculate_lines(cub->params->only_maps);
	wide = calculate_wide(cub->params->only_maps);
	player.lines_numbers = lines;
	player.map_copy = malloc(lines * sizeof(char *));
	while (i < lines)
	{
		player.map_copy[i] = ft_strdup(cub->params->only_maps[i]);
		i++;
	}
	player.wide = wide;
	player.x = 0;
	player.y = 0;
	player.angle = 0;
	player.fov = M_PI / 3.0;
	return (player);
}

void	main_screen(t_cub *cub)
{
	t_player	player;
	t_data		img;
	t_loop_data	loop_data;

	player = initialize_player(cub);
	textures(cub, &img);
	img.mlx = mlx_init();
//	img.mlx_win = mlx_new_window(img.mlx, WINDOW_WIDTH,
//			WINDOW_HEIGHT, "CUB#D");
//	img.img = mlx_new_image(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.mlx_win = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB#D");
	img.img = mlx_new_image(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	set_player_position(&player, player.map_copy);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	img.cub = cub;
	loop_data.img = &img;
	loop_data.player = &player;
	mlx_hook(img.mlx_win, 2, 1L << 0, key_press_hook, &player);
	mlx_hook(img.mlx_win, 17, 0, ft_close, &img);
	mlx_loop_hook(img.mlx, update_screen, &loop_data);
	mlx_clear_window(img.mlx, img.mlx_win);
	mlx_loop(img.mlx);
}
