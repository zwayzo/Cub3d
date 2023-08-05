/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_verification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:37:44 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/05 17:15:01 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    west_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    if (str[0] == 'W' && str[1] == 'E')
        cub->indices->WE_indice += 1;   
    // printf("west %d\n", cub->indices->WE_indice);
    west_var_exist(str, cub);
}

void    south_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    if (str[0] == 'S' && str[1] == 'O')
        cub->indices->SO_indice += 1;  
    // printf("south %d\n", cub->indices->SO_indice);  
    south_var_exist(str, cub);
}

void    east_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    if (str[0] == 'E' && str[1] == 'A')
        cub->indices->EA_indice += 1;     
    // printf("east %d\n", cub->indices->EA_indice);
    east_var_exist(str, cub);
}

void    nord_ver(char *str, t_cub *cub)
{
    int i;

    i = 0;
    if (str[0] == 'N' && str[1] == 'O')
        cub->indices->NO_indice += 1;
    nord_var_exist(str, cub);
    // printf("nord %d\n", cub->indices->NO_indice);
}
