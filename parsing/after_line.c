/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:43:20 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/12 23:13:35 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void after_line(t_cub *cub)
{
    int j;
    int i;

    i = cub->indices->begin_line + 1;
    j = 0;
    while (cub->params->maps[i])
    {
        while (cub->params->maps[i][j])
        {
            if ((ft_strlen(cub->params->maps[i])) > ft_strlen(cub->params->maps[i - 1]))
            {
                j = ft_strlen(cub->params->maps[i - 1]);
                while (cub->params->maps[i][j])
                {
                    if (cub->params->maps[i][j] == '0')
                    {
                        space_error();
                    }
                    j++;
                }
            }
            j++;
            if (j > ft_strlen(cub->params->maps[i]))
                break;
        }
        i++;
        j = 0;
    }
}


void after_line_down(t_cub *cub)
{
    int j;
    int i;

    i = cub->indices->begin_line;
    j = 0;
    while (cub->params->maps[i + 1])
    {
        while (cub->params->maps[i][j])
        {
            if ((ft_strlen(cub->params->maps[i])) > ft_strlen(cub->params->maps[i + 1]))
            {
                j = ft_strlen(cub->params->maps[i + 1]) - 1;
                // printf("%s\n", &cub->params->maps[i][j-1]);
                while (cub->params->maps[i][j])
                {
                    if (cub->params->maps[i][j] == '0')
                        space_error();
                    j++;
                }
            }
            j++;
            if (j > ft_strlen(cub->params->maps[i]))
                break;
        }
        i++;
        j = 0;
    }
}