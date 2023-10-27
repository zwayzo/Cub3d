/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:41:17 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/26 22:21:26 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	which_color(t_cub *cub, int i, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = cub->images[i].image_ptr
		+ (y * cub->images[i].size_line + x
			* (cub->images[i].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	render_sky(t_data *img, int x, int top_position, t_cub *cub)
{
	int	color;
	int	y;

	y = 0;
	color = create_rgb(cub->indices->ciel->red,
			cub->indices->ciel->green, cub->indices->ciel->blue);
	while (y < top_position)
	{
		if (y >= 0 && y < WINDOW_HEIGHT)
			my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	render_land(t_data *img, int x, int bottom_position, t_cub *cub)
{
	int	y;
	int	color;

	y = bottom_position;
	color = create_rgb(cub->indices->floor->red,
			cub->indices->floor->green, cub->indices->floor->blue);
	while (y < WINDOW_HEIGHT)
	{
		if (y >= 0 && y < WINDOW_HEIGHT)
			my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}
