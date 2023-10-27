/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:37:45 by nel-hark          #+#    #+#             */
/*   Updated: 2023/10/27 05:20:51 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	name_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	if (str[i] == 'b')
	{
		i -= 1;
		if (str[i] == 'u')
		{
			i -= 1;
			if (str[i] == 'c')
			{
				i -= 1;
				if (str[i] == '.')
					return (1);
			}
		}
	}
	printf("Error\n");
	exit(1);
}

int	count_lines(t_cub *cub)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	fd = open(cub->params->name, O_RDONLY);
	while (i == 0 || ft_strlen(s) != 0)
	{
		if (ft_strlen(s) != 0)
			free(s);
		i++;
		s = get_next_line(fd);
	}
	free(s);
	return (i - 1);
}

char	**map_stock(t_cub *cub)
{
	char	**str;
	int		i;
	int		fd;

	i = 0;
	fd = open(cub->params->name, O_RDONLY);
	str = malloc((cub->params->lines_numbers + 1) * sizeof(char *));
	while (i < cub->params->lines_numbers)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	ft_maps_stock(t_cub *cub)
{
	cub->params->lines_numbers = count_lines(cub);
	cub->params->maps = map_stock(cub);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	cub = malloc(sizeof(t_cub));
	cub->params = malloc(sizeof(t_param));
	cub->indices = malloc(sizeof(t_incice));
	name_check(av[1]);
	cub->params->name = av[1];
	ft_maps_stock(cub);
	colors_stock(cub);
	cub->params->only_maps = real_maps_stock(cub);
	maps_working(cub);
	player_env(cub);
	directions_details(cub);
	verification_char(cub->params->only_maps);
	main_screen(cub);
	ft_last_free(cub);
}
