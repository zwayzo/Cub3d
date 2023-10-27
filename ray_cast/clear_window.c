/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:42:44 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/26 20:16:14 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	update_screen(void *param)
{
	t_loop_data	*loop_data;
	t_cub		*cub;
	t_data		*img;
	t_player	*player;

	loop_data = (t_loop_data *)param;
	img = (loop_data->img);
	cub = img->cub;
	player = loop_data->player;
	mlx_clear_window(img->mlx, img->mlx_win);
	draw_3d(img, player, cub);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
