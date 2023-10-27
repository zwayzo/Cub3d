/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:57:48 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 04:28:46 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ffirst_one(t_cub *cub, int i, int j)
{
	if (cub->params->only_maps[i][j] == 'W'
		|| cub->params->only_maps[i][j] == 'S'
		|| cub->params->only_maps[i][j] == 'E'
		|| cub->params->only_maps[i][j] == 'N')
		return (1);
	return (0);
}

void	second_one(t_cub *cub, int i, int x)
{
	if (cub->params->only_maps[i][x] != '1'
			&& cub->params->only_maps[i][x] != cub->indices->player)
		global_error();
}

void	third_one(t_cub *cub, int flag, int j)
{
	if (flag == 0)
	{
		while (cub->params->only_maps[cub->a][cub->b + 1] == 32
			|| cub->params->only_maps[cub->a][cub->b + 1] == '\t')
				cub->b = cub->b + 1;
		second_one(cub, cub->a, cub->b);
	}
	else if (flag == 1)
	{
		while (cub->params->only_maps[cub->a][cub->b - 1] == 32
			|| cub->params->only_maps[cub->a][cub->b - 1] == '\t')
				cub->b = cub->b - 1;
		second_one(cub, cub->a, cub->b);
	}
	else if (flag == 2)
	{
		while (cub->params->only_maps[cub->b + 1][j] == 32
			|| cub->params->only_maps[cub->b + 1][j] == '\t')
			cub->b = cub->b + 1;
		second_one(cub, cub->b, j);
	}
}

void	mlast_one(t_cub *cub)
{
	while (cub->params->only_maps[cub->b - 1][cub->c] == 32
			|| cub->params->only_maps[cub->b - 1][cub->c] == '\t')
				cub->b--;
	second_one(cub, cub->b, cub->c);
}

void	player_env(t_cub *cub)
{
	cub->a = 0;
	cub->b = 0;
	cub->c = 0;
	while (cub->params->only_maps[cub->a])
	{
		while (cub->params->only_maps[cub->a][cub->c])
		{
			if (ffirst_one(cub, cub->a, cub->c))
			{
					cub->b = cub->c;
				third_one(cub, 0, cub->c);
					cub->b = cub->c;
				third_one(cub, 1, cub->c);
					cub->b = cub->a;
				third_one(cub, 2, cub->c);
				cub->b = cub->a;
				mlast_one(cub);
				break ;
			}
				cub->c++;
		}
		cub->c = 0;
		cub->a++;
	}
}
