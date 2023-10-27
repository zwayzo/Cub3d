/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_working.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:46 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 03:36:22 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	overflow(int i, int j, int x, int nb)
{
	if (j - i > 19 && x == -1)
		return (0);
	else if (j - i >= 19 && x == 1)
		return (-1);
	else
		return (nb * x);
}

int	my_function(int nb, int *j, const char *str)
{
	nb *= 10;
	nb += str[*j] - 48;
	*j = *j + 1;
	return (nb);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				x;
	unsigned long	nb;
	int				j;

	i = 0;
	nb = 0;
	x = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		nb = my_function(nb, &j, str);
	if (str[j] != '\0' && str[j] != 10)
		global_error();
	return (overflow(i, j, x, nb));
}

void	maps_working(t_cub *cub)
{
	first_wall(cub);
	first_one(cub);
	last_one(cub);
	last_wall(cub);
	player_param(cub);
	if (cub->indices->player_indice != 1)
	{
		printf("ERROR\n");
		exit (1);
	}
	space_checking(cub);
	after_line(cub);
	after_line_down(cub);
}

int	number_check(char *nb)
{
	if (ft_atoi(nb) < 0 || ft_atoi(nb) > 255)
		return (0);
	return (1);
}
