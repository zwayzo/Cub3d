/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_store.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:51 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 04:30:12 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	w_len(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

void	west_store(char *str, t_cub *cub)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = w_len(str);
	cub->indices->we_stock = calloc((len + 1), sizeof(char));
	while (str[i] == 32 || str[i] == '\t')
		i++;
	i = i + 2;
	if (i + 1 >= len)
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i] == 32 || str[i] == '\t')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != 32 && str[i] != '\t')
	{
		cub->indices->we_stock[j] = str[i];
		i++;
		j++;
	}
	cub->indices->we_stock[j] = '\0';
}

void	nord_store(char *str, t_cub *cub)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = w_len(str);
	cub->indices->no_stock = calloc((len + 1), sizeof(char));
	while (str[i] == 32 || str[i] == '\t')
		i++;
	i = i + 2;
	if (i + 1 >= len)
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i] == 32 || str[i] == '\t')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != 32 && str[i] != '\t')
	{
		cub->indices->no_stock[j] = str[i];
		i++;
		j++;
	}
	cub->indices->no_stock[j] = '\0';
}

void	south_store(char *str, t_cub *cub)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = w_len(str);
	cub->indices->so_stock = calloc((len + 1), sizeof(char));
	while (str[i] == 32 || str[i] == '\t')
		i++;
	i = i + 2;
	if (i + 1 >= len)
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i] == 32 || str[i] == '\t')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != 32 && str[i] != '\t')
	{
		cub->indices->so_stock[j] = str[i];
		i++;
		j++;
	}
	cub->indices->so_stock[j] = '\0';
}

void	east_store(char *str, t_cub *cub)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = w_len(str);
	cub->indices->ea_stock = calloc((len + 1), sizeof(char));
	while (str[i] == 32 || str[i] == '\t')
		i++;
	i = i + 2;
	if (i + 1 >= len)
	{
		printf("ERROR\n");
		exit (1);
	}
	while (str[i] == 32 || str[i] == '\t')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != 32 && str[i] != '\t')
	{
		cub->indices->ea_stock[j] = str[i];
		i++;
		j++;
	}
	cub->indices->ea_stock[j] = '\0';
}
