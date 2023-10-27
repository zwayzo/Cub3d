/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:21:54 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 04:35:06 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	be_careful(t_cub *cub, int i, int j, int *n)
{
	if (cub->params->maps[i][j] != '1'
		&& cub->params->maps[i][j] != '0'
		&& cub->params->maps[i][j] != 'W'
		&& cub->params->maps[i][j] != 'S'
		&& cub->params->maps[i][j] != 'E'
		&& cub->params->maps[i][j] != 'N'
		&& cub->params->maps[i][j] != '\n'
		&& cub->params->maps[i][j] != '\0')
	{
		*n = *n + 1;
		return (0);
	}
	return (1);
}

int	differente(int i, t_cub *cub)
{
	int	j;
	int	n;

	i = 0;
	n = 0;
	j = 0;
	while (cub->params->maps[i])
	{
		while (cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t')
		{
			j++;
		}
		baybay(cub, i, j);
		if ((cub->params->maps[i][j] == '0'
			|| cub->params->maps[i][j] == '1')
		&& n == 0)
		{
			cub->indices->begin_line = i;
			n++;
		}
		i++;
		j = 0;
	}
	return (cub->indices->begin_line);
}

int	ciel_detecte(t_cub *cub, int i, int j)
{
	if (cub->params->maps[i][j] == 'C'
	&& (cub->params->maps[i][j + 1] == 32
		|| cub->params->maps[i][j + 1] == '\t'
		|| cub->params->maps[i][j + 1] == '\n'))
		return (1);
	else if (cub->params->maps[i][j] == 'F'
	&& (cub->params->maps[i][j + 1] == 32
		|| cub->params->maps[i][j + 1] == '\t'
		|| cub->params->maps[i][j + 1] == '\n'))
		return (2);
	return (0);
}

void	colors_check(t_cub *cub)
{
	if (cub->indices->floor_indice != 1
		|| cub->indices->ciel_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	rgb_call_function(t_cub *cub, int i, int n)
{
	if (n == 1)
	{
		cub->indices->ciel_indice += 1;
		red_ciel_split(cub->params->maps[i], cub);
		green_ciel_split(cub->params->maps[i], cub);
		blue_ciel_split(cub->params->maps[i], cub);
	}
	else
	{
		cub->indices->floor_indice += 1;
		red_floor_split(cub->params->maps[i], cub);
		green_floor_split(cub->params->maps[i], cub);
		blue_floor_split(cub->params->maps[i], cub);
	}
}
