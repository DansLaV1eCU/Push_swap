/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:26 by llupache          #+#    #+#             */
/*   Updated: 2025/07/03 01:53:22 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*clean1(char **res, int count)
{
	while (count--)
		free(res[count]);
	free(res);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*word;

	start = *s;
	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	const char	*s_ptr;
	int			word_count;
	char		**result;
	int			count;

	if (!s)
		return (NULL);
	s_ptr = (char *)s;
	count = 0;
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (count < word_count)
	{
		result[count] = get_next_word(&s_ptr, c);
		if (!result[count])
			return (clean1(result, count));
		count++;
	}
	result[word_count] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	*str;
// 	char	**new;

// 	str = "";
// 	// new = ft_split("", 'a');
// 	// printf("%s", new[0]);
// 	if (!(new = ft_split("", 'z')))
// 		printf("NULL");
// 	else
// 	{
// 		if (!new[0])
// 			printf("ok\n");
// 	}
// 	// if (!new[0])
// 	// 	printf("ok\n");
// 	// while (*new != NULL)
// 	// {
// 	// 	printf("%s, ", *new);
// 	// 	new ++;
// 	// }
// }
