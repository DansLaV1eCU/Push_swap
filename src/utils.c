/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:15:23 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/28 21:40:50 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_new(long value)
{
    t_node	*node;

	node = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
    node->prev = NULL;
	node->value = value;
	return (node);
}

void lstadd_back(stack *stack_a, t_node* new)
{
    t_node	*current;
    int index;

    index = 0;
    if (stack_a->start == NULL)
    {
        stack_a->start = new;
        new->index = index;
    }
    else
    {
        current = stack_a->start;
		while (current->next != NULL)
        {
            current = current->next;
            index++;
        }
        new->index = index + 1;
		current->next = new;
        new->prev = current;
    }
}

void free_stack(stack* s)
{
    t_node *cur;

    if (!s->start)
        return ;
    while (s->start)
    {
        cur = s->start->next;
        free(s->start);
        s->start = cur;
    }
}

long	push_atoi(char *str)
{
	long		count_minus;
	int		count;
	long		result;

	count_minus = 1;
	count = 0;
	result = 0;
    while (((str[count] >= 9 && str[count] <= 13) || str[count] == 32))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count + 1] < '0' || str[count + 1] > '9')
			return (0);
		else if (str[count] == '-')
			count_minus = -1;
		count++;
	}
    if (str[count] && str[count] == '0' && str[count + 1] != '\0')
        return (0);
    while (str[count] >= '0' && str[count] <= '9')
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
    while (((str[count] >= 9 && str[count] <= 13) || str[count] == 32))
		count++;
    if (str[count] != '\0')
        return (0);
    return (result * count_minus);
}
