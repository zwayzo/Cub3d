/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RGB_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:23:28 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 01:45:14 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	global_error(void)
{
	printf("ERROR\n");
	exit (1);
}

void	red_floor_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;

	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			global_error();
		if (tmp[0])
		{
			t = ft_split(tmp[0], ' ');
			if (t[1] && number_finder(t[1]) && number_check(t[1]))
				cub->indices->floor->red = ft_atoi(t[1]);
			else
				global_error();
			double_free (t);
		}
		double_free (tmp);
	}
	else
		global_error();
}

void	green_floor_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;

	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			global_error();
		if (tmp[1])
		{
			t = ft_split(tmp[1], ' ');
			if (t[0] && number_finder(t[0]) && number_check(t[0]))
				cub->indices->floor->green = ft_atoi(t[0]);
			else
				global_error();
			double_free (t);
		}
		double_free (tmp);
	}
	else
		global_error();
}

void	blue_floor_split(char *str, t_cub *cub)
{
	char	**tmp;
	char	**t;

	if (comma_finder(str) == 2)
	{
		tmp = ft_split(str, ',');
		if (double_lenght(tmp) != 3)
			printf("ERROR");
		if (tmp[2])
		{
			t = ft_split(tmp[2], ' ');
			if (t[0] && number_finder(t[0]) && number_check(t[0]))
				cub->indices->floor->blue = ft_atoi(t[0]);
			else
				global_error();
			double_free (t);
		}
		double_free (tmp);
	}
	else
		global_error();
}
