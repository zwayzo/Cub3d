/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:00:18 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/08 14:12:16 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int double_lenght(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
void    double_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

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

int number_finder(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            return (1);
        i++;
    }
    return (0);
}