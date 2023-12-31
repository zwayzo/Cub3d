/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <nel-hark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:36:58 by moazzedd          #+#    #+#             */
/*   Updated: 2023/10/26 22:13:54 by nel-hark         ###   ########.fr       */
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
