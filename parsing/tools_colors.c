/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:00:18 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/26 22:02:25 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	double_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	comma_finder(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	number_finder(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	down_check(int i, t_cub *cub, int j)
{
	if (i + 1 >= cub->params->lines_numbers
		|| j >= ft_strlen(cub->params->maps[i + 1]))
		return (0);
	if ((cub->params->maps[i + 1]
			&& cub->params->maps[i + 1][j] != '0')
		|| (cub->params->maps[i + 1][j] == '0'
		&& (cub->params->maps[i][j] != 32
		&& cub->params->maps[i][j] != '\t')))
		return (0);
	return (1);
}
