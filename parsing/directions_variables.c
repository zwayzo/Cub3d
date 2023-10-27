/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:56:12 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 05:00:47 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	east_var_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	i = i + 2;
	if (!(ft_strlen(&str[i])))
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i])
		i++;
	i = i - 2;
	while (str[i] == 32 || str[i] == '\t')
		i--;
	if ((!(str[i] == 'm' && str[i - 1] == 'p'
				&& str[i - 2] == 'x' && str[i - 3] == '.'))
		&& (!(str[i] == 'g' && str[i - 1] == 'n'
				&& str[i - 2] == 'p' && str[i - 3] == '.')))
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	west_var_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	i = i + 2;
	if (!(ft_strlen(&str[i])))
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i])
		i++;
	i = i - 2;
	while (str[i] == 32 || str[i] == '\t')
		i--;
	if ((!(str[i] == 'm' && str[i - 1] == 'p'
				&& str[i - 2] == 'x' && str[i - 3] == '.'))
		&& (!(str[i] == 'g' && str[i - 1] == 'n'
				&& str[i - 2] == 'p' && str[i - 3] == '.')))
	{
		printf("ERROR!\n");
		exit (1);
	}
}

void	south_var_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	i = i + 2;
	if (!(ft_strlen(&str[i])))
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i])
		i++;
	i = i - 2;
	while (str[i] == 32 || str[i] == '\t')
		i--;
	if ((!(str[i] == 'm' && str[i - 1] == 'p'
				&& str[i - 2] == 'x' && str[i - 3] == '.'))
		&& (!(str[i] == 'g' && str[i - 1] == 'n'
				&& str[i - 2] == 'p' && str[i - 3] == '.')))
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	nord_var_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	i = i + 2;
	if (!(ft_strlen(&str[i])))
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i])
		i++;
	i = i - 2;
	while (str[i] == 32 || str[i] == '\t')
		i--;
	if ((!(str[i] == 'm' && str[i - 1] == 'p'
				&& str[i - 2] == 'x' && str[i - 3] == '.'))
		&& (!(str[i] == 'g' && str[i - 1] == 'n'
				&& str[i - 2] == 'p' && str[i - 3] == '.')))
	{
		printf("ERROR\n");
		exit (1);
	}
}

void	check_direction_nature(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O')
		nord_store(str, cub);
	if (str[i] == 'W' && str[i + 1] == 'E')
		west_store(str, cub);
	if (str[i] == 'E' && str[i + 1] == 'A')
		east_store(str, cub);
	if (str[i] == 'S' && str[i + 1] == 'O')
		south_store(str, cub);
}
