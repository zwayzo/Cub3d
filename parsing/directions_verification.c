/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_verification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:37:44 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/26 22:16:13 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	west_ver(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == 'W' && str[i + 1] == 'E'
		&& (str[i + 2] == '\t' || str[i + 2] == 32))
	{
		cub->indices->we_indice += 1;
		west_var_exist(str);
	}
}

void	south_ver(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == 'S' && str[i + 1] == 'O'
		&& (str[i + 2] == '\t' || str[i + 2] == 32))
	{
		cub->indices->so_indice += 1;
		south_var_exist(str);
	}
}

void	east_ver(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == 'E' && str[i + 1] == 'A'
		&& (str[i + 2] == '\t' || str[i + 2] == 32))
	{
		cub->indices->ea_indice += 1;
		east_var_exist(str);
	}
}

void	nord_ver(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O'
		&& (str[i + 2] == '\t' || str[i + 2] == 32))
	{
		cub->indices->no_indice += 1;
		nord_var_exist(str);
	}
}
