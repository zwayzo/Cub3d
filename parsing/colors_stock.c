/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:21:54 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/07 17:09:08 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


void    colors_check(t_cub *cub)
{
    if (cub->indices->floor_indice != 1
    || cub->indices->ciel_indice != 1)
    {
        printf("ERROR: Deplucate or miss F or C indice...!");
        exit (1);
    }
}
void colors_stock(t_cub *cub)
{
    int i;
    int j;
    int x = 0;

    i = 0;
    j = 0;
    cub->indices->ciel = malloc(sizeof(cub->indices->ciel));
    cub->indices->floor = malloc(sizeof(cub->indices->floor));
    while (cub->params->maps[i])
    {
        if (!(cub->params->maps[i][j] == '\n'))
        {
            while (cub->params->maps[i][j] == '\t'
            || cub->params->maps[i][j] == 32)
                j++;
            if (cub->params->maps[i][j] == 'C'
            && (cub->params->maps[i][j + 1] == 32 
            || cub->params->maps[i][j + 1] == '\t'
            || cub->params->maps[i][j + 1] == '\n'))
            {
                // printf("HEEEEEER\n");
                cub->indices->ciel_indice += 1;
                red_ciel_split(cub->params->maps[i], cub);
                green_ciel_split(cub->params->maps[i], cub);
                blue_ciel_split(cub->params->maps[i], cub);
                // printf("{%s}\n", cub->params->maps[i]);
            }
            else if (cub->params->maps[i][j] == 'F'
            && (cub->params->maps[i][j + 1] == 32 
            || cub->params->maps[i][j + 1] == '\t')
            || cub->params->maps[i][j + 1] == '\n')
            {
                // printf("enter\n");
                cub->indices->floor_indice += 1;
                red_floor_split(cub->params->maps[i], cub);
                green_floor_split(cub->params->maps[i], cub);
                blue_floor_split(cub->params->maps[i], cub);
                // char **tmp = ft_split(cub->params->maps[i], '=');
                // x = 0;
                // while (tmp[1][x] == 32 || tmp[1][x] == '\t')
                //     x++;
                // cub->indices->floor->blue = atoi(&tmp[1][x]);
                // printf("floor is |%d|\n", cub->indices->floor->blue);
            }
        }
        i++;
        j = 0;
    }
    colors_check(cub);
}