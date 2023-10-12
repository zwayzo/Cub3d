/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:14:10 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/12 22:20:04 by moazzedd         ###   ########.fr       */
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
        while ((cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t') && cub->params->maps[i][j])
            j++;
        // printf("1\n");
        if (cub->params->maps[i][j] != '1' && cub->params->maps[i][j] != ' ' && cub->params->maps[i][j] != '\t')
        {
            // printf("2\n");
            printf("ERROR: incomplet wall(first one)(line %d)...!", i - cub->indices->begin_line + 1);
            exit (1);
        }
        // printf("3\n");
        i++;
        j = 0;
    }
    
}

void    first_wall(t_cub *cub)
{
    int i;

    i = 0;
    // printf("%s\n", cub->params->maps[cub->indices->begin_line]);
    while (cub->params->maps[cub->indices->begin_line][i] == '1')
            i++;
    // printf("{%c}\n", cub->param  s->maps[cub->indices->begin_line][i]);
    if (cub->params->maps[cub->indices->begin_line][i] != '\0'
    && cub->params->maps[cub->indices->begin_line][i] != '\n')
    {
        // printf("%d\n", down_check(cub->indices->begin_line, cub, i));
        printf("ERROR: incomplet wall(first line)...!");
        exit (1);
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
        // printf(",,,1\n");
        if (cub->params->maps[j][i] != '1' && cub->params->maps[j][i] != ' ' && cub->params->maps[j][i] != '\t')
        {
            printf("ERROR: incomplet wall(last one)(line %d)...!", j - cub->indices->begin_line + 1);
            exit (1);
        }
        // printf("...2\n");
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
        if (cub->params->maps[i][j] != '1' && (cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t') && up_check(i, cub, j))
        {
            printf("ERROR: last wall incomplet...!");
            exit (1);
        }
        j++;
    }
}
