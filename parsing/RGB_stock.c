/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RGB_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:23:28 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/07 17:06:36 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int comma_finder(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ',')
            return (1);
        i++;
    }
    return (0);
}

void    red_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    tmp = ft_split(str, ',');
    if (tmp[0])
    {
        t = ft_split(tmp[0], ' ');
        // printf("%s\n", t[1]);
        // printf("in\n");
        if (t[1])
            cub->indices->ciel->red = atoi(t[1]);
    }// printf("red is |%d|\n", cub->indices->floor->red);
}

void    green_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    // printf("str --> is %s\n", str);
    tmp = ft_split(str, ',');
    if (tmp[1])
    {
        t = ft_split(tmp[1], ' ');
        // printf("pppppp\n");
        // printf("t[0] is %s\n", t[0]);
        // printf("|||\n");
        if (t[0])
            cub->indices->ciel->green = atoi(t[0]);
    }// printf("green is |%d|\n", cub->indices->floor->green);
}

void    blue_ciel_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;
    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        if (tmp[2])
        {
            t = ft_split(tmp[2], ' ');
            if (t[0])
                cub->indices->ciel->blue = atoi(t[0]);
        }
    }
}

void    red_floor_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;

    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        // printf("tmp is %s\n", tmp[0]);
        if (tmp[0])
        {
            t = ft_split(tmp[0], ' ');
            // printf("%s\n", t[1]);
            // printf("in\n");
            if (t[1])
                cub->indices->floor->red = atoi(t[1]);
        }
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
        if (tmp[1])
        {
            t = ft_split(tmp[1], ' ');
            // printf("pppppp\n");
            // printf("t[0] is %s\n", t[0]);
            // printf("|||\n"); 
            if (t[0])
                cub->indices->floor->green = atoi(t[0]);
        }
    }// printf("green is |%d|\n", cub->indices->floor->green);
}

void    blue_floor_split(char *str, t_cub *cub)
{
    char **tmp;
    char **t;

    if (comma_finder(str) == 1)
    {
        tmp = ft_split(str, ',');
        if (tmp[2])
        {
            t = ft_split(tmp[2], ' ');
            if (t[0])
                cub->indices->floor->blue = atoi(t[0]);
        }
    }
}