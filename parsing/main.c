#include "../cub.h"

int    name_check(char *str)
{
	int 	i;
	
	i = 0;
	while (str[i])
		i++;
	i -= 1;
	if (str[i] == 'b')
	{
		i -=1;
		if (str[i] == 'u')
		{
			i -=1;
			if (str[i] == 'c')
			{
				i -=1;
				if (str[i] == '.')
					return (1);
			}
		}
	}
	printf("Error: map's extention");
	exit(1);
}

int	count_lines(t_cub *cub)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	// printf("%s\n", cub->params->name);
	fd = open(cub->params->name, O_RDONLY);
	while (i == 0 || ft_strlen(s) != 0)
	{
		if (ft_strlen(s) != 0)
			free (s);
		i++;
		// printf("%d\n",i);
		s = get_next_line(fd);
		// printf("s is %s\n", s);
	}
	free (s);
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
	char	*tmp;
	char	*tmp_2;
	char	**to_r;
	// int		i;
	int		j;
	int		fd;
	cub->params->lines_numbers = count_lines(cub);
	// printf("{%d}\n", cub->params->lines_numbers);
	cub->params->maps = map_stock(cub);
	// int i = 0;
	// while (cub->params->maps[i])
	// {
	// 	// printf("{%s}\n", cub->params->maps[i]);
	// 	i++;
	// }
}



int main(int ac, char **av)
{
	int 	i;
	int 	j;
	int		fd;
	char	*tmp;
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->params = malloc(sizeof(t_param));
	cub->indices = malloc(sizeof(t_incice));
	if (ac != 2)
	{
		printf("Error: Not Enought Argguments...!");
		exit (1);
	}
	name_check(av[1]);
	fd = open(av[1], O_RDONLY);
	cub->params->name = av[1];
	ft_maps_stock(cub);
	directions_details(cub);
	// colors_storage(cub);
	printf("west = %s\n", cub->indices->WE_stock);
	printf("south = %s\n", cub->indices->SO_stock);
	printf("east = %s\n", cub->indices->EA_stock);
	printf("nord = %s\n", cub->indices->NO_stock);



	
}
