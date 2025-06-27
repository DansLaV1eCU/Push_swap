/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:44:47 by llupache          #+#    #+#             */
/*   Updated: 2024/09/30 18:15:24 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*clean(t_list *new_list, void (*del)(void *))
{
	t_list	*temp;

	while (new_list)
	{
		temp = new_list;
		new_list = new_list->next;
		if (del)
			ft_lstdelone(temp, del);
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	current = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (clean(new_list, del));
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (!new_list)
			new_list = new_node;
		else
			current->next = new_node;
		current = new_node;
		lst = lst->next;
	}
	return (new_list);
}
