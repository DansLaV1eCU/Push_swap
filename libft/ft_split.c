/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:26 by llupache          #+#    #+#             */
/*   Updated: 2024/09/30 18:42:07 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	length(char *str)
// {
// 	int	count;

// 	count = 0;
// 	while (str[count])
// 	{
// 		count++;
// 	}
// 	return (count);
// }

// long unsigned int	count_words(char *str, char c)
// {
// 	int	count;
// 	int	flag;
// 	int	words_count;

// 	count = 0;
// 	words_count = 0;
// 	flag = 1;
// 	while (str[count])
// 	{
// 		if (str[count] != c && flag == 1)
// 			words_count++;
// 		flag = 0;
// 		if (str[count] == c)
// 			flag = 1;
// 		count++;
// 	}
// 	return (words_count);
// }

// char	*create_word(char *str, char c, char **lst, int lst_index)
// {
// 	long unsigned int	len;
// 	int					count;
// 	char				*word;
// 	char				*temp;

// 	temp = str;
// 	len = 0;
// 	count = 0;
// 	while (*str && *str++ != c)
// 		len++;
// 	word = (char *)malloc(len * sizeof(char) + 1);
// 	str = temp;
// 	while (*str && *str != c)
// 		word[count++] = *str++;
// 	while (*str && *str == c)
// 		str++;
// 	word[count] = '\0';
// 	lst[lst_index] = word;
// 	return (str);
// }

// char	**ft_split(char *str, char c)
// {
// 	char	**list;
// 	int		list_count;

// 	if (!str)
// 		return (NULL);
// 	list = (char **)malloc(count_words(str, c) * sizeof(char *) + 1);
// 	if (!list)
// 		return (NULL);
// 	list_count = 0;
// 	while (*str)
// 	{
// 		if (*str != c)
// 			str = create_word(str, c, list, list_count++);
// 		else
// 			str++;
// 	}
// 	list[list_count] = NULL;
// 	return (list);
// }

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
