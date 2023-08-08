/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RGB_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:23:28 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/08 14:12:18 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    red_floor_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;

    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        if (double_lenght(tmp) != 3)
        {
            printf("ERROR: RGB parametres error..!");
            exit(1);
        }
        if (tmp[0])
        {
            t = ft_split(tmp[0], ' ');
            
            if (t[1] && number_finder(t[1]))
                cub->indices->floor->red = atoi(t[1]);
            else
            {
               double_free (t);
               printf("ERROR: missing RGB's parametres...!");
               exit(1); 
            }
            double_free (t);
        }
        double_free (tmp);
    }
}

void    green_floor_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    // printf("str --> is %s\n", str);
    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        if (double_lenght(tmp) != 3)
        {
            printf("ERROR: RGB parametres error..!");
            exit(1);
        }
        if (tmp[1])
        {
            t = ft_split(tmp[1], ' ');
            if (t[0] && number_finder(t[0]))
                cub->indices->floor->green = atoi(t[0]);
            else
            {
               double_free (t);
               printf("ERROR: missing RGB's parametres...!");
               exit(1); 
            }
            double_free (t);
        }
        double_free (tmp);
    }
    
}

void    blue_floor_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;

    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        if (double_lenght(tmp) != 3)
        {
            printf("ERROR: RGB parametres error..!");
        }
        if (tmp[2])
        {
            t = ft_split(tmp[2], ' ');
            if (t[0] && number_finder(t[0]))
                cub->indices->floor->blue = atoi(t[0]);
            else
            {
               double_free (t);
               printf("ERROR: missing RGB's parametres...!");
               exit(1); 
            }
            double_free (t);
        }
        double_free (tmp);
    }
}

