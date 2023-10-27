/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:14:10 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 03:43:12 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	first_one(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->params->only_maps[i])
	{
		while ((cub->params->only_maps[i][j] == 32
			|| cub->params->only_maps[i][j] == '\t')
			&& cub->params->only_maps[i][j])
			j++;
		if (cub->params->only_maps[i][j] != '1'
			&& cub->params->only_maps[i][j] != ' '
			&& cub->params->only_maps[i][j] != '\t')
		{
			printf("ERROR\n");
			exit (1);
		}
		i++;
		j = 0;
	}
}

void	first_wall(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->params->only_maps[0][i] == '1'
		|| cub->params->only_maps[0][i] == 32
		|| cub->params->only_maps[0][i] == '\t')
		i++;
	if (cub->params->only_maps[0][i] != '\0'
	&& cub->params->only_maps[0][i] != '\n')
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	last_one(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->params->only_maps[j + 1])
	{
		while (cub->params->only_maps[j][i + 2])
			i++;
		if (cub->params->only_maps[j][i] != '1'
			&& cub->params->only_maps[j][i] != ' '
			&& cub->params->only_maps[j][i] != '\t')
		{
			printf("ERROR\n");
			exit (1);
		}
		j++;
		i = 0;
	}
}

void	last_wall(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->params->only_maps[i + 1])
		i++;
	while (cub->params->only_maps[i][j] == 32 ||
		cub->params->only_maps[i][j] == '\t')
		j++;
	while (cub->params->only_maps[i][j + 1])
	{
		if (cub->params->only_maps[i][j] != '1'
			&& (cub->params->only_maps[i][j] == 32
			|| cub->params->only_maps[i][j] == '\t')
			&& up_check(i, cub, j))
		{
			printf("ERROR\n");
			exit (1);
		}
		j++;
	}
}
