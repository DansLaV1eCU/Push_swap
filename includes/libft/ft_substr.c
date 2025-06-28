/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:18:08 by llupache          #+#    #+#             */
/*   Updated: 2024/09/29 23:49:39 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	unsigned int	start1;
	char			*substr;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	start1 = start;
	count = 0;
	while (s[start1++] && count < len)
		count++;
	substr = (char *)malloc(count * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	count = 0;
	while (count < len && s[count])
	{
		substr[count] = s[start];
		start++;
		count++;
	}
	substr[count] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*new;

// 	str = "hello";
// 	new = ft_substr("hola", 3, 2);
// 	printf("%s", new);
// }
