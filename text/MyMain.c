/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyMain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:59:45 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/26 22:12:58 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	textures(t_cub *cub, t_data *img)
{
	int		i;
	char	*tmp_text[4];
	void	*timg;

	i = 0;
	tmp_text[0] = cub->indices->we_stock;
	tmp_text[1] = cub->indices->so_stock;
	tmp_text[2] = cub->indices->ea_stock;
	tmp_text[3] = cub->indices->no_stock;
	while (i < 4)
	{
		timg = mlx_xpm_file_to_image(img->mlx, tmp_text[i],
				&cub->images[i].width, &cub->images[i].height);
		if (timg == NULL)
		{
			printf("Image loading failed for %s\n", cub->indices->we_stock);
			exit(1);
		}
		cub->images[i].image_ptr = mlx_get_data_addr(timg,
				&cub->images[i].bits_per_pixel, &cub->images[i].size_line,
				&cub->images[i].endian);
		i++;
	}
}
