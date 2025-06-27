/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/30 19:02:50 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_str)
{
	unsigned char	*new;
	int				count;

	count = ft_strlen(str);
	new = (unsigned char *)str;
	while (count != -1)
	{
		if (new[count] == (unsigned char)search_str)
			return ((char *)&new[count]);
		count--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	*new;

// 	str = "teste";
// 	c = '\0';
// 	new = ft_strrchr(str, c);
// 	if (new)
// 	{
// 		printf("%s", new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
