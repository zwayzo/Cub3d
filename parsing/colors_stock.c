/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:21:54 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/13 13:52:20 by moazzedd         ###   ########.fr       */
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
    while (cub->params->maps[i] && (cub->indices->ciel_indice == 0
    || cub->indices->floor_indice == 0))
    {
        // printf("{%s}\n", cub->params->maps[i]);
        // printf("{%d}{%d}\n", cub->indices->ciel_indice, cub->indices->floor_indice);
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
                cub->indices->ciel_indice += 1;
                red_ciel_split(cub->params->maps[i], cub);
                green_ciel_split(cub->params->maps[i], cub);
                blue_ciel_split(cub->params->maps[i], cub);
            }
            else if (cub->params->maps[i][j] == 'F'
            && (cub->params->maps[i][j + 1] == 32 
            || cub->params->maps[i][j + 1] == '\t')
            || cub->params->maps[i][j + 1] == '\n')
            {
                cub->indices->floor_indice += 1;
                red_floor_split(cub->params->maps[i], cub);
                green_floor_split(cub->params->maps[i], cub);
                blue_floor_split(cub->params->maps[i], cub);
            }
        }
        i++;
        j = 0;
    }
    j = 0;
    int n = 0;
    while (n == 0 && cub->params->maps[i])
    {
        // printf("%s\n", cub->params->maps[i]);
        while (n == 0 && cub->params->maps[i][j])
        {
            // printf("|%c|\n", cub->params->maps[i][j]);
            if (cub->params->maps[i][j] != 32
            && cub->params->maps[i][j] != '\t'
            && cub->params->maps[i][j] != '\n')
            {
                n++;
                break;
            };
            j++;
        }
        i++;
        j = 0;
    }
    i = i - 1;
    // i++;
    // printf("{%d}{%d}\n", cub->indices->ciel_indice, cub->indices->floor_indice);
    // printf("i {%d}\n", i);
    cub->indices->begin_line = i;
    // printf("begin line {%d}\n", cub->indices->begin_line);
    colors_check(cub);
}