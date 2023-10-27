/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:26:52 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 05:01:56 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_wall(char tile)
{
	return (tile == '1');
}

int	is_valid_map_position(int x, int y, int player_wide, int lines_numbers)
{
	return (x >= 0 && x < player_wide && y >= 0 && y < lines_numbers);
}

int	check_collision(char **map, int map_x, int map_y, t_player *player)
{
	char	tile_x;
	char	tile_y;
	char	tile_xy;
	int		can_move_x;
	int		can_move_y;

	tile_x = map[map_y][map_x];
	tile_y = map[(int)(player->y / TILE_SIZE)][map_x];
	tile_xy = map[map_y][(int)(player->x / TILE_SIZE)];
	if (!is_wall(tile_x) && !is_wall(tile_xy))
		can_move_x = true;
	else
		can_move_x = false;
	if (!is_wall(tile_y) && !is_wall(tile_xy))
		can_move_y = true;
	else
		can_move_y = false;
	return (can_move_x && can_move_y);
}

void	update_position(t_player *player, double new_x,
		double new_y, int can_move)
{
	if (can_move)
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	move_player(t_player *player, double dx, double dy, char **map)
{
	double	new_x;
	double	new_y;
	int		can_move;
	int		map_y;
	int		map_x;

	new_x = player->x + dx;
	new_y = player->y + dy;
	map_x = (int)(new_x / TILE_SIZE);
	map_y = (int)(new_y / TILE_SIZE);
	if (is_valid_map_position(map_x, map_y,
			player->wide, player->lines_numbers))
	{
		can_move = check_collision(map, map_x, map_y, player);
		update_position(player, new_x, new_y, can_move);
	}
}
