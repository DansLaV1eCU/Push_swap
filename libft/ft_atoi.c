/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:14:34 by llupache          #+#    #+#             */
/*   Updated: 2024/09/29 20:51:29 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		count_minus;
	int		count;
	int		result;
	char	*str1;

	str1 = (char *)str;
	count_minus = 1;
	count = 0;
	result = 0;
	while (((str1[count] >= 9 && str1[count] <= 13) || str1[count] == 32))
		count++;
	if (str1[count] == '-' || str1[count] == '+')
	{
		if (str1[count + 1] < '0' || str1[count + 1] > '9')
			return (0);
		else if (str1[count] == '-')
			count_minus = -1;
		count++;
	}
	while (str1[count] >= '0' && str1[count] <= '9')
	{
		result = result * 10 + (str1[count] - '0');
		count++;
	}
	return (result * count_minus);
}

// int	main(void)
// {
// 	char	*str;
// 	int		result1;

// 	str = "++123";
// 	result1 = ft_atoi(str);
// 	printf("%d", result1);
// 	return (0);
// }
