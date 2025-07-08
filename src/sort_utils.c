/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:40:59 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/08 18:43:18 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	t_node	*temp;
	t_node	*min;

	temp = a->start;
	min = a->start;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min->index);
}

int	find_max(t_stack *a)
{
	t_node	*temp;
	t_node	*max;

	temp = a->start;
	max = a->start;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max->index);
}

void	sort_three_items_stack(t_stack *a)
{
	if (a->start->value > a->start->next->value
		&& a->end->value < a->end->prev->value)
		swap_one_stack(a, 1);
	else if (a->end->value < a->end->prev->value
		&& a->start->value < a->end->value)
		swap_one_stack(a, 1);
	if (a->start->value < a->start->next->value
		&& a->end->prev->value < a->end->value)
		return ;
	else if (a->end->value > a->end->prev->value
		&& a->end->value < a->start->value)
		rotate_one_stack(a, 1);
	else if (a->start->value > a->start->next->value
		&& a->end->value > a->start->value)
		swap_one_stack(a, 1);
	else
		reverse_rotate_one_stack(a, 1);
}

void	rotate_first(t_stack *a, t_node *node)
{
	int	index_in_a;

	index_in_a = find_lowest_bigger(a, node->value);
	if (a->len / 2 >= index_in_a)
		while (index_in_a-- != 0)
			rotate_one_stack(a, 1);
	else
		while (index_in_a++ != a->len)
			reverse_rotate_one_stack(a, 1);
}

void	rotate_to_min_at_top(t_stack *a)
{
	int	index;

	index = find_min(a);
	if (a->len / 2 >= index)
		while (index-- != 0)
			rotate_one_stack(a, 1);
	else
		while (index++ != a->len)
			reverse_rotate_one_stack(a, 1);
}
