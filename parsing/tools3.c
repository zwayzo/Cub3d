/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 04:32:25 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 04:45:47 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	baybay(t_cub *cub, int i, int j)
{
	if (cub->params->maps[i][j] != '1'
		&& cub->params->maps[i][j] != '0'
		&& cub->params->maps[i][j] != 'W'
		&& cub->params->maps[i][j] != 'S'
		&& cub->params->maps[i][j] != 'E'
		&& cub->params->maps[i][j] != 'N'
		&& cub->params->maps[i][j] != '\n'
		&& cub->params->maps[i][j] != '\0'
		&& cub->params->maps[i][j] != 'F'
		&& cub->params->maps[i][j] != 'C')
	{
		printf("ERROR...!\n");
		exit (1);
	}
}

void	first_line_detecte(t_cub *cub, int i)
{
	int	x;

	cub->n = 0;
	cub->j = 0;
	i = cub->params->lines_numbers - 1;
	while (i > 0 && cub->n == 0)
	{
		while (cub->params->maps[i][cub->j] == 32
			|| cub->params->maps[i][cub->j] == '\t')
			cub->j++;
		be_careful(cub, i, cub->j, &cub->n);
		i--;
		cub->j = 0;
	}
	x = ++i;
	while (cub->params->maps[i])
	{
		second_last_function(cub, i, &cub->j);
		if (last_helpful_function(cub, i, cub->j) == 1)
			break ;
		i++;
		cub->j = 0;
	}
	cub->indices->begin_line = differente(i, cub);
	colors_check (cub);
}

char	**to_split(char **tmp, char *str)
{
	tmp = ft_split(str, ',');
	if (double_lenght(tmp) != 3)
		global_error();
	return (tmp);
}

int	mylasterror(char *t)
{
	if (t && number_finder(t) && number_check(t))
		return (ft_atoi(t));
	else
		global_error();
	return (0);
}
