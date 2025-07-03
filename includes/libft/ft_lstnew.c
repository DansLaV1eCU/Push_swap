/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:44:47 by llupache          #+#    #+#             */
/*   Updated: 2025/07/03 01:00:08 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstnew(void *content)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->content = content;
	return (node);
}
