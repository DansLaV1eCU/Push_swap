/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:12:28 by llupache          #+#    #+#             */
/*   Updated: 2025/06/27 18:15:46 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cycle(int nb, int count)
{
	char	number;

	if (nb != 0)
	{
		count = cycle(nb / 10, count + 1);
		number = (nb % 10) + '0';
		write(1, &number, 1);
	}
	return (count);
}

int	ft_putnbr(int nb, int count)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
		return (count);
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	count = cycle(nb, count);
	return (count);
}
