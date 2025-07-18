/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:15:23 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/18 18:30:44 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_node	*node_new(long value)
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

void	lstadd_back(t_stack *stack_a, t_node *new)
{
	t_node	*current;

	if (stack_a->start == NULL)
	{
		stack_a->start = new;
		stack_a->end = new;
		new->index = 0;
		new->next = NULL;
		stack_a->len++;
	}
	else
	{
		current = stack_a->start;
		while (current->next != NULL)
			current = current->next;
		new->index = stack_a->len;
		stack_a->len++;
		current->next = new;
		new->prev = current;
		stack_a->end = new;
	}
}

long	push_atoi(char *str)
{
	long	count_minus;
	int		count;
	long	result;

	count_minus = 1;
	count = 0;
	result = 0;
	while (((str[count] >= 9 && str[count] <= 13) || str[count] == 32))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count + 1] < '0' || str[count + 1] > '9')
			return (10000000000);
		else if (str[count] == '-')
			count_minus = -1;
		count++;
	}
	while (str[count] == '0')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	if (str[count] != '\0' && (str[count] <= 9 || str[count] >= 13)
		&& str[count] != 32)
		return (10000000000);
	return (result * count_minus);
}

void	print_stack(t_stack *s)
{
	t_node	*temp;

	ft_printf("t_stack %c - length %d\n", s->name, s->len);
	if (s->start)
		ft_printf("Start value %d - start index %d\n", s->start->value,
			s->start->index);
	else
		ft_printf("Start value NULL - start index NULL\n");
	if (s->end)
		ft_printf("End value %d - end index %d\n\n", s->end->value,
			s->end->index);
	else
		ft_printf("End value NULL - end index NULL\n\n");
	temp = s->start;
	while (temp)
	{
		ft_printf("Index: %d - Value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
}
