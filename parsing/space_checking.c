/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:20:11 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:23 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    space_error()
{
    printf("ERROR: Space and 0..!\n");
    exit (1);
}

int up_check(int i, t_cub *cub, int j)
{
    // printf("i %d | begin %d\n", i, cub->indices->begin_line);
    // printf("i %d | %d\n", i, cub->params->lines_numbers);
    // printf("|%c|\n", cub->params->maps[i][j]);
    // printf("i-1 {%c}\n", cub->params->maps[i - 1][j]);
    // printf("i-1 {%s}\n", &cub->params->maps[i - 1][j]);
    // printf("{%s}\n", &cub->params->maps[i - 1][j]);
    // printf("{%c}\n", cub->params->maps[i][j]);

    if (i- 1 <= cub->indices->begin_line)
        return (0);
    if (cub->params->maps[i - 1][j] != '0')
        return (0);
    return (1);
}

int down_check(int i, t_cub *cub, int j)
{
    // printf("||||| %d | %d\n", j ,ft_strlen(cub->params->maps[i + 1]));
    // printf("-------->%s, %d\n", &cub->params->maps[i][j], j);
    // printf("i %d | %d\n", i, cub->params->lines_numbers);
    // printf("|%c||%c|\n", cub->params->maps[i+1][j], cub->params->maps[i][j]);
    // printf("{%c}\n", cub->params->maps[i + 1][j]);
    if (i + 1 >= cub->params->lines_numbers || j >= ft_strlen(cub->params->maps[i + 1]))
        return (0);
    if ((cub->params->maps[i + 1]
        && cub->params->maps[i + 1][j] != '0')
        || (cub->params->maps[i + 1][j] == '0' && (cub->params->maps[i][j] != 32 && cub->params->maps[i][j] != '\t')))
        return (0); 
    return (1);
}

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
                if (j > 0 && cub->params->maps[i][j - 1] == '0'
                    && (cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t'))
                    {
                        // printf("j is %d\n", j);
                        // printf("---->|%s|\n", &cub->params->maps[i][0]);
                        // printf("---->|%s|\n", &cub->params->maps[i][j - 1]);
                        // printf("---->|%c|\n", cub->params->maps[i][j]);
                        space_error();
                    }
                    
                // printf("{%s}\n", cub->params->maps[i]);
                while ((cub->params->maps[i][j] == 32
                    || cub->params->maps[i][j] == '\t')
                     && (down_check(i, cub, j) == 0)
                     && (up_check(i, cub, j) == 0))
                        j++;
                // printf("---->|%c|\n", cub->params->maps[i][j]); 
                if ((cub->params->maps[i][j] == '0')
                || up_check(i, cub, j - 1) == 1 || down_check(i, cub, j) == 1)
                    {
                        // printf("up=%d | down=%d\n", up /_check(i, cub, j), down_check(i, cub, j));
                        // printf("---->|%c|\n", cub->params->maps[i][j]);
                        space_error();
                    }
            }
            j++;
        }
        j = 0;
        i++;
    }
}
