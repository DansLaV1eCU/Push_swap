/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/30 19:49:43 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*chr;

	chr = (unsigned char *)s;
	while (*chr != (unsigned char)c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return ((char *)chr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	*new;

// 	str = "hello";
// 	c = 'a';
// 	new = strchr(str, c);
// 	if (new)
// 	{
// 		printf("%c", *new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
