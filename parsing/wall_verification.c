/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:14:10 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/13 15:05:13 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    first_one(t_cub *cub)
{
    int i;
    int j;

    j = 0;
    i = cub->indices->begin_line;
    while (cub->params->maps[i + 1])
    {
        while (cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t')
            j++;
        if (cub->params->maps[i][j] != '1')
        {
            printf("ERROR: incomplet wall(first one)(line %d)...!", i - cub->indices->begin_line + 1);
            exit (1);
        }
        i++;
        j = 0;
    }
    
}

void    first_wall(t_cub *cub)
{
    int i;

    i = 0;
    while (cub->params->maps[cub->indices->begin_line][i]== 32 
        || cub->params->maps[cub->indices->begin_line][i]== '\t')
        i++;
    while (cub->params->maps[cub->indices->begin_line][i + 1])
    {
        if (cub->params->maps[cub->indices->begin_line][i] != '1')
        {
            printf("ERROR: incomplet wall(first line)...!");
            exit (1);
        }
        i++;
    }
}

void    last_one(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    j = cub->indices->begin_line;
    while (cub->params->maps[j + 1])
    {
        while (cub->params->maps[j][i + 2])
            i++;
        // printf("|%c|\n", cub->params->maps      /[j][]);
        if (cub->params->maps[j][i] != '1')
        {
            printf("ERROR: incomplet wall(last one)(line %d)...!", j - cub->indices->begin_line + 1);
            exit (1);
        }
        j++;
        i = 0;
    }
}

void    last_wall(t_cub *cub)
{
    int i;
    int j;
    
    j = 0;
    i = cub->indices->begin_line;
    while (cub->params->maps[i + 1])
        i++;
    while (cub->params->maps[i][j] == 32 ||
        cub->params->maps[i][j] == '\t')
        j++;
    while (cub->params->maps[i][j + 1])
    {
        if (cub->params->maps[i][j] != '1')
        {
            printf("ERROR: last wall incomplet...!");
            exit (1);
        }
        j++;
    }
}
