/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:38:08 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/26 20:53:07 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialize_ray(t_raycast *ray_data, double ray_x,
	double ray_y, double ray_angle)
{
	ray_data->distance = 0.5;
	ray_data->top_position = 0;
	ray_data->bottom_position = 0;
	ray_data->flag = -1;
	ray_data->ray_x = ray_x;
	ray_data->ray_y = ray_y;
	ray_data->map_x = 0;
	ray_data->map_y = 0;
	ray_data->ray_dist_x = fabs(1 / cos(ray_angle));
	ray_data->ray_dist_y = fabs(1 / sin(ray_angle));
	if (cos(ray_angle) > 0)
		ray_data->step_x = 1;
	else if (cos(ray_angle) < 0)
		ray_data->step_x = -1;
	if (sin(ray_angle) > 0)
		ray_data->step_y = 1;
	else if (sin(ray_angle) < 0)
		ray_data->step_y = -1;
}

void	update_ray_data(t_raycast *ray_data, double ray_angle)
{
	if (ray_data->ray_dist_x < ray_data->ray_dist_y)
	{
		ray_data->ray_x += ray_data->step_x;
		ray_data->ray_dist_x += fabs(1 / cos(ray_angle));
		ray_data->map_x = (int)(ray_data->ray_x / TILE_SIZE);
		ray_data->map_y = (int)(ray_data->ray_y / TILE_SIZE);
		ray_data->flag = 0;
	}
	else
	{
		ray_data->ray_y += ray_data->step_y;
		ray_data->ray_dist_y += fabs(1 / sin(ray_angle));
		ray_data->map_x = (int)(ray_data->ray_x / TILE_SIZE);
		ray_data->map_y = (int)(ray_data->ray_y / TILE_SIZE);
		ray_data->flag = 1;
	}
}

int	hit_wall(t_raycast *ray_data, t_player *player,
	char **map, double *wall_distance)
{
	char	tile;

	if (ray_data->map_x >= 0 && ray_data->map_x < player->wide
		&& ray_data->map_y >= 0 && ray_data->map_y < player->lines_numbers)
	{
		tile = map[ray_data->map_y][ray_data->map_x];
		if (tile == '1')
		{
			*wall_distance = sqrt((ray_data->ray_x - player->x)
					* (ray_data->ray_x - player->x)
					+ (ray_data->ray_y - player->y)
					* (ray_data->ray_y - player->y));
			return (1);
		}
	}
	return (0);
}

t_raycast	cast_ray(t_player *player, double ray_angle, char **map)
{
	t_raycast	result;
	double		wall_distance;
	int			wall_hit;

	initialize_ray(&result, player->x, player->y, ray_angle);
	wall_distance = 0.0;
	wall_hit = 0;
	result.view_angle = ray_angle;
	while (result.distance < MAX_RAY_DISTANCE)
	{
		update_ray_data(&result, ray_angle);
		wall_hit = hit_wall(&result, player, map, &wall_distance);
		if (wall_hit)
		{
			result.c_distance = wall_distance * cos(ray_angle - player->angle);
			result.w_h = (100.0 / result.c_distance) * (WINDOW_HEIGHT / 2.0);
			result.m_w = WINDOW_HEIGHT / 2.0;
			result.top_position = result.m_w - (int)(result.w_h / 2.0);
			result.bottom_position = result.m_w + (int)(result.w_h / 2.0);
			break ;
		}
	}
	return (result);
}
