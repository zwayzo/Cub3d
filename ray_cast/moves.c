/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:43:48 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 04:46:20 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rotate_player(t_player *player, double rotation_speed)
{
	player->angle += rotation_speed;
}

int	key_press_hook(int keycode, t_player *player)
{
	double	move_speed;
	double	rotation_speed;

	move_speed = 40.0;
	rotation_speed = 5 * (M_PI / 180);
	if (keycode == 13)
		move_player(player, cos(player->angle) * move_speed,
			sin(player->angle) * move_speed, player->map_copy);
	else if (keycode == 1)
		move_player(player, -cos(player->angle) * move_speed,
			-sin(player->angle) * move_speed, player->map_copy);
	else if (keycode == 2)
		move_player(player, cos(player->angle + (M_PI / 2)) * move_speed,
			sin(player->angle + (M_PI / 2)) * move_speed, player->map_copy);
	else if (keycode == 0)
		move_player(player, -cos(player->angle + (M_PI / 2)) * move_speed,
			-sin(player->angle + (M_PI / 2)) * move_speed, player->map_copy);
	else if (keycode == 124)
		rotate_player(player, rotation_speed);
	else if (keycode == 123)
		rotate_player(player, -rotation_speed);
	else if (keycode == 53)
		exit(0);
	return (0);
}
