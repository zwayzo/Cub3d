/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:43:20 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 05:19:07 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_loop(int *i, int *j, t_cub *cub)
{
	if (cub->params->maps[*i][*j] == '0')
		space_error();
	*j = *j + 1;
}

void	after_line(t_cub *cub)
{
	int	j;
	int	i;

	i = cub->indices->begin_line + 1;
	j = 0;
	while (cub->params->maps[i])
	{
		while (cub->params->maps[i][j])
		{
			if ((ft_strlen(cub->params->maps[i]))
				> ft_strlen(cub->params->maps[i - 1]))
			{
				j = ft_strlen(cub->params->maps[i - 1]);
				while (cub->params->maps[i][j])
					my_loop(&i, &j, cub);
			}
			j++;
			if (j > ft_strlen(cub->params->maps[i]))
				break ;
		}
		i++;
		j = 0;
	}
}

void	after_line_down(t_cub *cub)
{
	int	j;
	int	i;

	i = cub->indices->begin_line;
	j = 0;
	while (cub->params->maps[i + 1])
	{
		while (cub->params->maps[i][j])
		{
			if ((ft_strlen(cub->params->maps[i]))
				> ft_strlen(cub->params->maps[i + 1]))
			{
				j = ft_strlen(cub->params->maps[i + 1]) - 1;
				while (cub->params->maps[i][j])
					my_loop(&i, &j, cub);
			}
			j++;
			if (j > ft_strlen(cub->params->maps[i]))
				break ;
		}
		i++;
		j = 0;
	}
}

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	colors_stock(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cub->indices->ciel = malloc(sizeof(t_colors));
	cub->indices->floor = malloc(sizeof(t_colors));
	ft_init(cub);
	while (cub->params->maps[i])
	{
		if (!(cub->params->maps[i][j] == '\n'))
		{
			while (cub->params->maps[i][j] == '\t'
			|| cub->params->maps[i][j] == 32)
				j++;
			if (ciel_detecte(cub, i, j) == 1)
				rgb_call_function(cub, i, 1);
			if (ciel_detecte(cub, i, j) == 2)
				rgb_call_function(cub, i, 2);
		}
		i++;
		j = 0;
	}
	first_line_detecte(cub, i);
}
