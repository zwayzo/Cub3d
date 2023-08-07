/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_verification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:37:44 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/07 01:08:52 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    west_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    while (str[i] == 32 || str[i] == '\t')
        i++;
    // printf("%d\n",i);
    // printf("{{%s}", &str[i]);
    if (str[i] == 'W' && str[i + 1] == 'E'
        && (str[i + 2] == '\t' || str[i + 2] == 32))
    {
        cub->indices->WE_indice += 1;   
        west_var_exist(str, cub);
    }
        // printf("west %d\n", cub->indices->WE_indice);
}

void    south_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    while (str[i] == 32 || str[i] == '\t')
        i++;
    if (str[i] == 'S' && str[i + 1] == 'O'
        && (str[i + 2] == '\t' || str[i + 2] == 32))
    {
        cub->indices->SO_indice += 1;  
        south_var_exist(str, cub);
        // printf("south %d\n", cub->indices->SO_indice);  
    }
}

void    east_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    while (str[i] == 32 || str[i] == '\t')
        i++;
    if (str[i] == 'E' && str[i + 1] == 'A'
        && (str[i + 2] == '\t' || str[i + 2] == 32))
    {
        cub->indices->EA_indice += 1;     
        // printf("east %d\n", cub->indices->EA_indice);
        east_var_exist(str, cub);
    }
}

void    nord_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    while (str[i] == 32 || str[i] == '\t')
        i++;
    if (str[i] == 'N' && str[i + 1] == 'O'
        && (str[i + 2] == '\t' || str[i + 2] == 32))
    {
        cub->indices->NO_indice += 1;
        nord_var_exist(str, cub);
    }// printf("nord %d\n", cub->indices->NO_indice);
}
