/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:56:12 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/17 00:08:25 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    east_var_exist(char *str, t_cub *cub)
{
    //  printf("east {%s}\n", str);
    int i;
    (void) cub;

    i = 0;
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
        i++;
    i = i + 2;
    if (!(ft_strlen(&str[i])))
    {
        printf("ERROR: EAST has no indication...!");
        exit (1);
    }
    while (str[i])
        i++;
    i = i - 2;
    // printf("{%c} {%c} {%c} {%c}\n", str[i], str[i-1], str[i-2],str[i-3]);
    if (!(str[i] == 'm' && str[i - 1] == 'p'
        && str[i - 2] == 'x' && str[i - 3] == '.'))
        {
            printf("ERROR: EAST extention not valid...!");
            exit (1);
        }
}

void    west_var_exist(char *str, t_cub *cub)
{
    //  printf("west {%s}\n", str);
    int i;
    (void) cub;

    i = 0;
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
        i++;
    i = i + 2;
    if (!(ft_strlen(&str[i])))
    {
        printf("ERROR: EAST has no indication...!");
        exit (1);
    }
    while (str[i])
        i++;
    i = i - 2;
    // printf("{%c} {%c} {%c} {%c}\n", str[i], str[i-1], str[i-2],str[i-3]);
    if (!(str[i] == 'm' && str[i - 1] == 'p'
        && str[i - 2] == 'x' && str[i - 3] == '.'))
        {
            printf("ERROR: WEST extention not valid...!");
            exit (1);
        }
}

void    south_var_exist(char *str, t_cub *cub)
{
    //  printf("south {%s}\n", str);
    int i;
    (void) cub;

    i = 0;
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
        i++;
    i = i + 2;
    if (!(ft_strlen(&str[i])))
    {
        printf("ERROR: SOUTH has no indication...!");
        exit (1);
    }
    while (str[i])
        i++;
    i = i - 2;
    // printf("{%c} {%c} {%c} {%c}\n", str[i], str[i-1], str[i-2],str[i-3]);
    if (!(str[i] == 'm' && str[i - 1] == 'p'
        && str[i - 2] == 'x' && str[i - 3] == '.'))
        {
            printf("ERROR: SOUTH extention not valid...!");
            exit (1);
        }
}

void    nord_var_exist(char *str, t_cub *cub)
{
    int i;
    (void) cub;
    //  printf("nord{%s}\n", str);

    i = 0;
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
        i++;
    i = i + 2;
    if (!(ft_strlen(&str[i])))
    {
        printf("ERROR: NORD has no indication...!");
        exit (1);
    }
    while (str[i])
        i++;
    i = i - 2;
    //  printf("nord {%s}\n", str);
    // printf("{%c} {%c} {%c} {%c}\n", str[i], str[i-1], str[i-2],str[i-3]);
    if (!(str[i] == 'm' && str[i - 1] == 'p'
        && str[i - 2] == 'x' && str[i - 3] == '.'))
        {
            printf("ERROR: NORD extention not valid...!");
            exit (1);
        }
}

void check_direction_nature(char *str, t_cub *cub)
{
    int i;

    i = 0;
    // printf("her\n");
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == 'N' && str[i + 1] == 'O')
        nord_store(str, cub);
    if (str[i] == 'W' && str[i + 1] == 'E')
        west_store(str, cub);
    if (str[i] == 'E' && str[i + 1] == 'A')
        east_store(str, cub);
    if (str[i] == 'S' && str[i + 1] == 'O')
        south_store(str, cub);
    // printf("out\n");
}