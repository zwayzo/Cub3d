/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_details.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:31:33 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 01:43:29 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_directions_init(t_cub *cub)
{
	cub->indices->no_indice = 0;
	cub->indices->so_indice = 0;
	cub->indices->ea_indice = 0;
	cub->indices->we_indice = 0;
}

void	check_for_deplucate(t_cub *cub)
{
	if (cub->indices->we_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
	if (cub->indices->so_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
	if (cub->indices->ea_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
	if (cub->indices->no_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	directions_details(t_cub *cub)
{
	int	i;

	i = 0;
	ft_directions_init(cub);
	i = 0;
	while (cub->params->maps[i])
	{
		if (cub->params->maps[i][0] != '\n')
		{
			check_direction_nature(cub->params->maps[i], cub);
			west_ver(cub->params->maps[i], cub);
			south_ver(cub->params->maps[i], cub);
			east_ver(cub->params->maps[i], cub);
			nord_ver(cub->params->maps[i], cub);
		}
		i++;
	}
	check_for_deplucate(cub);
}
