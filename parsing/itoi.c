/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:20:35 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/27 00:00:02 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*case_negative(int nb, char *ptr)
{
	ptr[1] = nb + 48;
	ptr[2] = '\0';
	return (ptr);
}

char	*convertir(int nb, char *ptr, int i, int s)
{
	int	j;

	j = i;
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
		if (nb >= 0 && nb <= 9)
			return (case_negative(nb, ptr));
	}
	while (i != s)
	{
		ptr[i-- - 1] = nb % 10 + 48;
		if (nb / 10 <= 9)
		{
			ptr[i - 1] = nb / 10 + 48;
			break ;
		}
		else
			nb = nb / 10;
	}
	ptr[j] = '\0';
	return (ptr);
}

void	case_special(int *i, int *n)
{
	if (*n < 0)
	{
		*i = *i + 1;
		*n = -*n;
	}
	while (*n > 9)
	{
		*i = *i + 1;
		*n = *n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		nb;

	i = 1;
	if (n == -2147483648)
	{
		ptr = (char *)malloc(12 * sizeof(char));
		ptr[0] = '-';
		ptr[1] = '2';
		n = 147483648;
		return (convertir(n, ptr, 11, 2));
	}
	nb = n;
	if (n < 0 || n > 9)
		case_special(&i, &n);
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	return (convertir(nb, ptr, i, 0));
}

int	last_helpful_function(t_cub *cub, int i, int j)
{
	if (cub->params->maps[i][j] != '\t'
		&& cub->params->maps[i][j] != 32
		&& cub->params->maps[i][j] != '\0'
		&& cub->params->maps[i][j] != '\n')
		return (1);
	return (0);
}
