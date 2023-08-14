/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:20:11 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/14 15:34:11 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    space_checking(t_cub *cub)
{
    int i;
    int j;

    i = cub->indices->begin_line;
    j = 0;
    while (cub->params->maps[i])
    {
        while (cub->params->maps[i][j])
        {
            if (cub->params->maps[i][j] == 32
                || cub->params->maps[i][j] == '\t')
            {
                // printf("{%s}\n", cub->params->maps[i]);
                while (cub->params->maps[i][j] == 32
                    || cub->params->maps[i][j] == '\t')
                        j++;
                // printf("|%s|\n", &cub->params->maps[i][j]); 
                if (!(cub->params->maps[i][j] == '\n' || cub->params->maps[i][j] == '\t' || cub->params->maps[i][j] == '\0' || cub->params->maps[i][j] == '1'))
                {
                    printf("ERROR: Space and 0..!\n");
                    exit (1);
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
}