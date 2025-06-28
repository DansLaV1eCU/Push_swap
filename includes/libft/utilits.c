/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:40:04 by llupache          #+#    #+#             */
/*   Updated: 2025/06/27 18:15:45 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_chr(const char c)
{
	write(1, &c, 1);
}

int	print_str(char *str, int count)
{
	if (!str)
	{
		count += 6;
		write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	int i = 34;
// 	printf("%X", 13);
// }
