/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciel_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:58:26 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 05:36:50 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_init(t_cub *cub)
{
	cub->indices->ciel->blue = 0;
	cub->indices->ciel->green = 0;
	cub->indices->ciel->red = 0;
	cub->indices->floor->blue = 0;
	cub->indices->floor->green = 0;
	cub->indices->floor->red = 0;
	cub->indices->ciel_indice = 0;
	cub->indices->floor_indice = 0;
}

void	red_ciel_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;
	int		x;

	x = 0;
	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			global_error();
		if (tmp[0])
		{
			t = ft_split(tmp[0], ' ');
			if (t[2])
				global_error();
			if (t[1] && number_finder(t[1]) && number_check(t[1]))
				cub->indices->ciel->red = ft_atoi(t[1]);
			else
				global_error();
			double_free (t);
		}
		double_free(tmp);
	}
	else
		global_error();
}

void	green_ciel_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;
	int		x;

	x = 0;
	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			global_error();
		if (tmp[1])
		{
			t = ft_split(tmp[1], ' ');
			if (t[1])
				global_error();
			if (t[0] && number_finder(t[0]) && number_check(t[0]))
				cub->indices->ciel->green = ft_atoi(t[0]);
			else
				global_error();
			double_free (t);
		}
		double_free(tmp);
	}
	else
		global_error();
}

void	blue_ciel_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;
	int		x;

	x = 0;
	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			global_error();
		if (tmp[2])
		{
			t = ft_split(tmp[2], ' ');
			if (t[1] && t[1][0] != '\n')
				global_error();
			if (t[0] && number_finder(t[0]) && number_check(t[0]))
				cub->indices->ciel->blue = ft_atoi(t[0]);
			else
				global_error();
			double_free (t);
		}
		double_free(tmp);
	}
	else
		global_error();
}
