/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:08:34 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 03:49:46 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_x(t_raycast raycast, t_cub *cub, int which)
{
	double	ray_point;
	int		tile_coordinate;
	double	fractional_x;
	int		texture_x;
	double	texture_offset;

	ray_point = 0;
	if (raycast.flag == 1)
		ray_point = raycast.ray_x;
	else if (raycast.flag == 0)
		ray_point = raycast.ray_y;
	tile_coordinate = (int)(ray_point / TILE_SIZE);
	fractional_x = ray_point - (tile_coordinate * TILE_SIZE);
	texture_offset = fractional_x / TILE_SIZE;
	texture_x = texture_offset * cub->images[which].width;
	return (texture_x);
}

//2-e 0-w 3-n 1-s
int	determine_wall_side(double sin_value, double cos_value, int flag)
{
	int	side;

	side = -1;
	if (flag == 0)
	{
		if (cos_value > 0)
			side = 2;
		else
			side = 0;
	}
	else if (flag == 1)
	{
		if (sin_value > 0)
			side = 3;
		else
			side = 1;
	}
	return (side);
}

void	render_wall(t_data *img, int x, t_raycast raycast, double ray_angle)
{
	t_cub	*cub;
	int		i;
	double	myx;
	double	myy;

	cub = raycast.cub;
	i = raycast.top_position;
	raycast.which = determine_wall_side(sin(ray_angle),
			cos(ray_angle), raycast.flag);
	myx = get_x(raycast, cub, raycast.which);
	if (raycast.w_h > WINDOW_HEIGHT)
	{
		i = 0;
		raycast.bottom_position = WINDOW_HEIGHT;
		myy = ((raycast.w_h - WINDOW_HEIGHT) / 2)
			* (cub->images[raycast.which].height / raycast.w_h);
	}
	while (i < raycast.bottom_position)
	{
		raycast.color = which_color(cub, raycast.which, myx, myy);
		my_mlx_pixel_put(img, x, i, raycast.color);
		myy = myy + cub->images[raycast.which].height / raycast.w_h;
		i++;
	}
}

void	draw_3d(t_data *img, t_player *player, t_cub *cub)
{
	t_raycast	result;
	double		start_angle;
	int			num_rays;
	double		ray_spacing;
	int			x;

	start_angle = player->angle - (player->fov / 2.0);
	num_rays = WINDOW_WIDTH;
	ray_spacing = player->fov / num_rays;
	x = 0;
	while (x < num_rays)
	{
		player->ray_angle = start_angle + (x * ray_spacing);
		result = cast_ray(player, player->ray_angle, player->map_copy);
		result.cub = cub;
		if (x >= 0 && x < WINDOW_WIDTH)
		{
			render_sky(img, x, result.top_position, cub);
			render_wall(img, x, result, player->ray_angle);
			render_land(img, x, result.bottom_position, cub);
		}
		x++;
	}
}
