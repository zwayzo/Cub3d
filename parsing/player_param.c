/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:43:43 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/13 15:04:50 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    player_param(t_cub *cub)
{
    int i;
    int j;

    i = cub->indices->begin_line;
    j = 0;
    cub->indices->player_indice = 0;
    while (cub->params->maps[i])
    {
        while (cub->params->maps[i][j])
        {
            if (cub->params->maps[i][j] == 'W' 
            || cub->params->maps[i][j] == 'E'
            || cub->params->maps[i][j] == 'S'
            || cub->params->maps[i][j] == 'N')
            {
                cub->indices->player_indice++;
                cub->indices->player = cub->params->maps[i][j];
            }
            j++;
        }
        j = 0;
        i++;
    }
}
