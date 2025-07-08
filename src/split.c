/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:26 by llupache          #+#    #+#             */
/*   Updated: 2025/07/08 20:00:32 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*clean1(char **res, int count)
{
	while (count--)
		free(res[count]);
	free(res);
	return (NULL);
}

int	count_words1(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != 32 && (*s <= 9 || *s >= 13) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == 32 || (*s >= 9 && *s <= 13))
			in_word = 0;
		s++;
	}
	return (count);
}

char	*get_next_word1(const char **s)
{
	const char	*start;
	size_t		len;
	char		*word;

	start = *s;
	while (**s && (**s == 32 || (**s >= 9 && **s <= 13)))
		(*s)++;
	start = *s;
	while (**s && (**s != 32 && (**s <= 9 || **s >= 13)))
		(*s)++;
	len = *s - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**split(const char *s)
{
	const char	*s_ptr;
	int			word_count;
	char		**result;
	int			count;

	if (!s || !*s)
		return (NULL);
	s_ptr = (char *)s;
	count = 0;
	word_count = count_words1(s);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (count < word_count)
	{
		result[count] = get_next_word1(&s_ptr);
		if (!result[count])
			return (clean1(result, count));
		count++;
	}
	result[word_count] = NULL;
	return (result);
}
