/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:43:43 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 04:30:35 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	player_param(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cub->indices->player_indice = 0;
	while (cub->params->only_maps[i])
	{
		while (cub->params->only_maps[i][j])
		{
			if (cub->params->only_maps[i][j] == 'W'
			|| cub->params->only_maps[i][j] == 'E'
			|| cub->params->only_maps[i][j] == 'S'
			|| cub->params->only_maps[i][j] == 'N')
			{
				cub->indices->player_indice++;
				cub->indices->player = cub->params->only_maps[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_last_free(t_cub *cub)
{
	double_free(cub->params->maps);
	free (cub->indices->ciel);
	free (cub->indices->floor);
	free (cub->indices->no_stock);
	free (cub->indices->we_stock);
	free (cub->indices->so_stock);
	free (cub->indices->ea_stock);
	free (cub->indices);
	free (cub->params);
	free (cub);
}

void	verification_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S'
			&& map[i][j] != 'N'
			&& map[i][j] != 32 && map[i][j] != '\t'
			&& map[i][j] != '\n' && map[i][j] != '\0')
			{
				printf("ERROR\n");
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	second_last_function(t_cub *cub, int i, int *j)
{
	while (cub->params->maps[i][*j]
		&& (cub->params->maps[i][*j] == 32
		|| cub->params->maps[i][*j] == '\t'))
		*j = *j + 1;
}
