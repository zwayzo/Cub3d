/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:12 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/26 14:56:28 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_player_position(t_player *py, char **map)
{
	py->j = -1;
	py->i = -1;
	while (map[++py->i])
	{
		py->j = -1;
		while (map[py->i][++py->j])
		{
			if (map[py->i][py->j] == 'S' || map[py->i][py->j] == 'N' ||
				map[py->i][py->j] == 'E' || map[py->i][py->j] == 'W')
			{
				py->x = ((double)py->j + 0.5) * TILE_SIZE;
				py->y = ((double)py->i + 0.5) * TILE_SIZE;
				if (map[py->i][py->j] == 'S')
					py->angle = 270 * (M_PI / 180);
				else if (map[py->i][py->j] == 'N')
					py->angle = 90 * (M_PI / 180);
				else if (map[py->i][py->j] == 'W')
					py->angle = 180 * (M_PI / 180);
				else
					py->angle = 0;
				return ;
			}
		}
	}
}
