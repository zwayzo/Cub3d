/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_details.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:31:33 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/17 00:08:44 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    ft_directions_init(t_cub *cub)
{
    cub->indices->NO_indice = 0;
    cub->indices->SO_indice = 0;
    cub->indices->EA_indice = 0;
    cub->indices->WE_indice = 0;
}


void    check_for_deplucate(t_cub *cub)
{
    // printf("%d\n", cub->indices->WE_indice);
    if (cub->indices->WE_indice != 1)
    {
        printf("ERROR: indication deplucate or manque (WE)...!");
        exit (1);
    }
    if (cub->indices->SO_indice != 1)
    {
        printf("ERROR: indication deplucate or manque (SO)...!");
        exit (1);
    }
    if (cub->indices->EA_indice != 1)
    {
        printf("ERROR: indication deplucate or manque (EA)...!");
        exit (1);
    }
    if (cub->indices->NO_indice != 1)
    {
        printf("ERROR: indication deplucate or manque (NO)...!");
        exit (1);
    }
}



void    directions_details(t_cub *cub)
{
    int i;

    i = 0;
    ft_directions_init(cub);
    
    i = 0;
    while (cub->params->maps[i])
    {
        if (cub->params->maps[i][0] != '\n')
        {
            // printf("{%s}\n", cub->params->maps[i]);
            check_direction_nature(cub->params->maps[i], cub);
            west_ver(cub->params->maps[i], cub);
            south_ver(cub->params->maps[i], cub);
            east_ver(cub->params->maps[i], cub);
            nord_ver(cub->params->maps[i], cub);
        }
        i++;
        // printf("\n\n");
    }
    check_for_deplucate(cub);
    
    
    
}
