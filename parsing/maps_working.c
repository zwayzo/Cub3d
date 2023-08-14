/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_working.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:46 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/14 15:27:16 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    maps_working(t_cub *cub)
{
    first_wall(cub);
    first_one(cub);
    last_one(cub);
    last_wall(cub);
    player_param(cub);
    if (cub->indices->player_indice != 1)
    {
        printf("ERROR: Player Deplucate or Manque...!");
        exit (1);
    }
    space_checking(cub);
    
    
}