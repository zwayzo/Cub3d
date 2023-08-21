/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:21:54 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/21 14:43:17 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    first_line_detecte(t_cub *cub, int i)
{
    int n;
    int j;

    n = 0;
    j = 0;
    while (n == 0 && cub->params->maps[i])
    {
        while (n == 0 && cub->params->maps[i][j])
        {
            if (cub->params->maps[i][j] != 32
            && cub->params->maps[i][j] != '\t'
            && cub->params->maps[i][j] != '\n')
                n++;
            j++;
        }
        i++;
        j = 0;
    }
    i = i - 1;
    cub->indices->begin_line = i;
    colors_check(cub);   
}

int ciel_detecte(t_cub *cub, int i, int j)
{
    if (cub->params->maps[i][j] == 'C'
        && (cub->params->maps[i][j + 1] == 32 
        || cub->params->maps[i][j + 1] == '\t'
        || cub->params->maps[i][j + 1] == '\n'))
            return (1);
    else if (cub->params->maps[i][j] == 'F'
        && (cub->params->maps[i][j + 1] == 32 
        || cub->params->maps[i][j + 1] == '\t'
        || cub->params->maps[i][j + 1] == '\n'))
                return (2);
    return (0);
}

void    colors_check(t_cub *cub)
{
    if (cub->indices->floor_indice != 1
    || cub->indices->ciel_indice != 1)
    {
        printf("ciel %d | floor %d\n", cub->indices->ciel_indice, cub->indices->floor_indice);
        printf("ERROR: Deplucate or miss F or C indice...!");
        exit (1);
    }
}

void    RGB_call_function(t_cub *cub, int i, int n)
{
    if (n == 1)
    {
        cub->indices->ciel_indice += 1;
        red_ciel_split(cub->params->maps[i], cub);
        green_ciel_split(cub->params->maps[i], cub);
        blue_ciel_split(cub->params->maps[i], cub);
    }
    else
    {
        cub->indices->floor_indice += 1;
        red_floor_split(cub->params->maps[i], cub);
        green_floor_split(cub->params->maps[i], cub);
        blue_floor_split(cub->params->maps[i], cub);
    }
}

void colors_stock(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = 0;
    cub->indices->ciel = malloc(sizeof(t_colors));
    cub->indices->floor = malloc(sizeof(t_colors));
    ft_init(cub);
    // printf("HER %d %d\n", cub->indices->floor_indice, cub->indices->ciel_indice);
    while (cub->params->maps[i] && (cub->indices->ciel_indice == 0
    || cub->indices->floor_indice == 0))
    {
        if (!(cub->params->maps[i][j] == '\n'))
        {
            while (cub->params->maps[i][j] == '\t'
            || cub->params->maps[i][j] == 32)
                j++;
            if (ciel_detecte(cub, i, j) == 1)
                RGB_call_function(cub, i, 1);
            else if (ciel_detecte(cub, i, j) == 2)
                RGB_call_function(cub, i, 2);
        }
        i++;
        j = 0;
    }
    first_line_detecte(cub, i);
}
