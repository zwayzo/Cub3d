/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciel_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:58:26 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/13 21:52:15 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    red_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    tmp = ft_split(str, ',');
    if (double_lenght(tmp) != 3)
    {
        printf("ERROR: RGB parametres error..!");
        exit (1);
    }
    if (tmp[0])
    {
        t = ft_split(tmp[0], ' ');
        if (t[1] && number_finder(t[1]))
            cub->indices->ciel->red = atoi(t[1]);
        else
        {
            double_free (t);
            printf("ERROR: missing RGB's parametres...!");
            exit(1); 
        }
    }
}

void    green_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
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
            cub->indices->ciel->green = atoi(t[0]);
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

void    blue_ciel_split(char *str, t_cub *cub)
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
        if (tmp[2])
        {
            t = ft_split(tmp[2], ' ');
            if (t[0] && number_finder(t[0]))
                cub->indices->ciel->blue = atoi(t[0]);
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
