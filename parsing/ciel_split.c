/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciel_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:58:26 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/21 14:50:20 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


void    ft_init(t_cub *cub)
{
    cub->indices->ciel->blue = 0;
    cub->indices->ciel->green = 0;
    cub->indices->ciel->red = 0;
    cub->indices->floor->blue = 0;
    cub->indices->floor->green = 0;
    cub->indices->floor->red = 0;
    cub->indices->ciel_indice = 0;
    cub->indices->floor_indice = 0;
}
void    red_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    // cub->indices->ciel = malloc(sizeof(t_colors));
    cub->indices->ciel->red = 0;
    t = NULL;
    // printf("|%d|\n", cub->indices->ciel->red);
    tmp = ft_split(str, ',');
    if (double_lenght(tmp) != 3)
    {
        printf("ERROR: RGB parametres error..!");
        exit (1);
    }
    if (tmp[0])
    {
        t = ft_split(tmp[0], ' ');
        // printf("HEEEEEEER\n");
        // printf("{%d{{\n", cub->indices->ciel->red);
        if (t[1] && number_finder(t[1]) && number_check(t[1]))
            cub->indices->ciel->red = ft_atoi(t[1]);
        else
        {
            double_free (t);
            printf("ERROR: RGB's parametres...!");
            exit(1); 
        }
    }
    double_free(t);
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
        if (t[0] && number_finder(t[0]) && number_check(t[0]))
            cub->indices->ciel->green = ft_atoi(t[0]);
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
    // printf("str is %s\n", str);
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
            if (t[0] && number_finder(t[0]) && number_check(t[0]))
                cub->indices->ciel->blue = ft_atoi(t[0]);
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
