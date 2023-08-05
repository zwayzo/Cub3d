/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:36:58 by moazzedd          #+#    #+#             */
/*   Updated: 2023/08/01 15:18:42 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	hexa(unsigned long long dec, int i, int flag)
{
	int	count;

	count = 0;
	if (dec < 0)
	{
		dec *= -1;
		count += ft_putchar('-');
	}
	if (dec >= (unsigned long long)i)
			count += hexa(dec / i, i, flag);
	if (flag == 0)
		count += ft_putchar(HEX[dec % i]);
	else
		count += ft_putchar(HEX_MAJ[dec % i]);
	return (count);
}
