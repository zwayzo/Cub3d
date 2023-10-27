/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:20:11 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 01:45:21 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	space_error(void)
{
	printf("ERRORn");
	exit (1);
}

int	up_check(int i, t_cub *cub, int j)
{
	if (j > ft_strlen(cub->params->maps[i - 1]))
		return (0);
	if (ft_strlen(cub->params->maps[i - 1]) >= j
		&& cub->params->maps[i - 1][j] != '0')
		return (0);
	return (1);
}

int	my_nfunction(int i, int j, t_cub *cub)
{
	if (j > 0 && cub->params->maps[i][j - 1] == '0'
		&& (cub->params->maps[i][j] == 32
		|| cub->params->maps[i][j] == '\t'))
		return (1);
	return (0);
}

void	ft_inc_loop(t_cub *cub, int i, int *j)
{
	while ((cub->params->maps[i][*j] == 32
		|| cub->params->maps[i][*j] == '\t')
		&& (down_check(i, cub, *j) == 0)
		&& (up_check(i, cub, *j) == 0)
		&& cub->params->maps[i][*j])
		*j = *j + 1;
}

void	space_checking(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->indices->begin_line;
	j = 0;
	while (cub->params->maps[i])
	{
		while (cub->params->maps[i][j])
		{
			if (cub->params->maps[i][j] == 32
				|| cub->params->maps[i][j] == '\t')
			{
				if (my_nfunction(i, j, cub) == 1)
					space_error();
				ft_inc_loop(cub, i, &j);
				if ((cub->params->maps[i][j] == '0')
				|| up_check(i, cub, j) == 1 || down_check(i, cub, j) == 1)
					space_error();
			}
			j++;
		}
		j = 0;
		i++;
	}
}
