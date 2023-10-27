/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_maps_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:15:44 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 03:34:00 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**real_maps_stock(t_cub *cub)
{
	int		i;
	int		j;
	char	**str;

	i = cub->indices->begin_line;
	j = 0;
	str = malloc ((cub->params->lines_numbers - cub->indices->begin_line + 1)
			* sizeof(char *));
	while (cub->params->maps[i])
	{
		str[j] = malloc((ft_strlen(cub->params->maps[i]) + 1) * sizeof(char));
		str[j] = strcpy(str[j], cub->params->maps[i]);
		i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}
