/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2024/09/29 23:30:30 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && *s1 && *s2)
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

// 	c1 = "abcdefghij";
// 	c2 = "abcdefgxyz";
// 	printf("%d", strncmp(c1, c2, 3));
// 	printf("%d", ft_strncmp(c1, c2, 3));
// }
