/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_working.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:46 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/09 20:14:32 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    maps_working(t_cub *cub)
{
    int i;

    i = 0;
    first_wall(cub);
    first_one(cub);
    last_one(cub);
    last_wall(cub);
    
    
}