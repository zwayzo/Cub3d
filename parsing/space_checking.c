/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:20:11 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/12 23:11:07 by moazzedd         ###   ########.fr       */
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
    // printf("welcome\n");
    // printf("i %d | j %d\n", i, j);
    // printf("i %d | %d\n", i, cub->params->lines_numbers);
    // printf("|%c|\n", cub->params->maps[i][j]);
    // printf("i-1 {%d}%d\n", ft_strlen(cub->params->maps[i - 1]), j);
    // printf("i-1 {%s}\n", &cub->params->maps[i - 1][j]);
    // printf("----------------------\n {%s}\n", cub->params->maps[i - 1]);
    // printf("her {%s}\n-----------------\n", &cub->params->maps[i][j]);
    if (j > ft_strlen(cub->params->maps[i - 1]))
    {
        // printf("1now\n");
        return (0);
    }
    // printf("no\n");
    if (ft_strlen(cub->params->maps[i - 1]) >= j &&  cub->params->maps[i - 1][j] != '0')
    {
        // printf("٠٠٠٠٠٠ {%s}\n{%s}\n", &cub->params->maps[i][j], &cub->params->maps[i - 1][j]);
        // printf("2now\n");
        return (0);
    }
    // printf("now-->0\n");
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
        // printf("line is %s\n", cub->params->maps[i]);
        while (cub->params->maps[i][j])
        {
            if (cub->params->maps[i][j] == 32
                || cub->params->maps[i][j] == '\t')
            {
                
                // // printf("j is %d\n", j);
                // printf("---->|%s|\n", &cub->params->maps[i][j]);
                // printf("---->|%s|\n", &cub->params->maps[i-1][j]);
                // printf("---||->|%s|\n", cub->params->maps[i]);
                if (j > 0 && cub->params->maps[i][j - 1] == '0'
                    && (cub->params->maps[i][j] == 32 || cub->params->maps[i][j] == '\t'))
                    {
                        // printf("this\n");
                        space_error();
                    }
                // printf("{%s}\n", cub->params->maps[i]);
                while ((cub->params->maps[i][j] == 32
                    || cub->params->maps[i][j] == '\t')
                     && (down_check(i, cub, j) == 0)
                     && (up_check(i, cub, j) == 0)
                     && cub->params->maps[i][j])
                     {
                // printf("%d | %d | %d\n", i,j, ft_strlen(cub->params->maps[i]));
                // printf("|%s|\n", &cub->params->maps[i][j]);
                // printf("|%s|\n", &cub->params->maps[i-1][j]);
                
                        j++;
                //     printf("incccccccc\n");
                // printf("%d | %d | %d\n", i,j, ft_strlen(cub->params->maps[i]));
                // printf("|%s|\n", &cub->params->maps[i][j]);
                // printf("|%s|\n", &cub->params->maps[i-1][j]);
                     }
                    //  printf("OUT\n");
                // printf("---->|%c|\n", cub->params->maps[i][j]); 
                if ((cub->params->maps[i][j] == '0')
                || up_check(i, cub, j ) == 1 || down_check(i, cub, j) == 1)
                    {
                // printf("{}{}{}{}________________\n");
                //         printf("up=%d | down=%d\n", up_check(i, cub, j), down_check(i, cub, j));
                //         printf("---->|%s|\n", cub->params->maps[i]);
                //         printf("---->|%c|\n", cub->params->maps[i][j]);
                        space_error();
                    }
            }
            j++;
        }
        j = 0;
        i++;
    }
}
