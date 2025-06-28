/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2024/09/29 23:46:53 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			count;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	count = 0;
	while (count < n && s1 && s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		count++;
	}
	if (count < n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}

// int	main(void)
// {
// 	char	*c1;
// 	char	*c2;

// 	c1 = "abc";
// 	c2 = "abc";
// 	printf("%d", ft_memcmp((void *)c1, (void *)c2, 7));
// }
