/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_store.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:51 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/05 16:42:55 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int w_len(char *str)
{
    int i;
    int j;

    i = 2;
    j = 0;
    while (str[i] == 32 || str[i] == '\t')
        i++;
    j = i;
    while (str[j])
        j++;
    return (j);
}

void    west_store(char *str, t_cub *cub)
{
    // printf("{%s}\n", str);
    int len;
    int i;
    int j;

    i = 2;
    j = 0;
    len = w_len(str);
    cub->indices->WE_stock = malloc((len + 1) * sizeof(char));
    while (str[i] == 32 || str[i] == '\t')
        i++;
    while (str[i])
    {
        cub->indices->WE_stock[j] = str[i];
        i++;
        j++;
    }
    cub->indices->WE_stock[j] = '\0';
}

void    nord_store(char *str, t_cub *cub)
{
    // printf("{%s}\n", str);
    int len;
    int i;
    int j;

    i = 2;
    j = 0;
    len = w_len(str);
    cub->indices->NO_stock = malloc((len + 1) * sizeof(char));
    while (str[i] == 32 || str[i] == '\t')
        i++;
    while (str[i])
    {
        cub->indices->NO_stock[j] = str[i];
        i++;
        j++;
    }
    cub->indices->NO_stock[j] = '\0';
}

void    south_store(char *str, t_cub *cub)
{
    // printf("{%s}\n", str);
    int len;
    int i;
    int j;

    i = 2;
    j = 0;
    len = w_len(str);
    cub->indices->SO_stock = malloc((len + 1) * sizeof(char));
    while (str[i] == 32 || str[i] == '\t')
        i++;
    while (str[i])
    {
        cub->indices->SO_stock[j] = str[i];
        i++;
        j++;
    }
    cub->indices->SO_stock[j] = '\0';
}

void    east_store(char *str, t_cub *cub)
{
    // printf("{%s}\n", str);
    int len;
    int i;
    int j;

    i = 2;
    j = 0;
    len = w_len(str);
    cub->indices->EA_stock = malloc((len + 1) * sizeof(char));
    while (str[i] == 32 || str[i] == '\t')
        i++;
    while (str[i])
    {
        cub->indices->EA_stock[j] = str[i];
        i++;
        j++;
    }
    cub->indices->EA_stock[j] = '\0';
}
