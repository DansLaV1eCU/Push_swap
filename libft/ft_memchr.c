/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/30 19:44:06 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int search_str, size_t n)
{
	unsigned char	*new;
	size_t			count;

	count = 0;
	new = (unsigned char *)str;
	while (count < n)
	{
		if (*new == (unsigned char)search_str)
			return ((void *)new);
		count++;
		new++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	*new;

// 	str = "hello";
// 	c = 'l';
// 	new = memchr((void *)str, c, 3);
// 	if (new)
// 	{
// 		printf("%c", *new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
