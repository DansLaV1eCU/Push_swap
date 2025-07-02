/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:36:52 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/02 20:08:35 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_push(t_stack *a, t_stack *b, t_node *node)
{
	int	index_in_b;
	int	index_in_a;

	index_in_b = find_biggest_lower(b, node->value);
	index_in_a = node->index;
	while (index_in_a > 0 && index_in_b > 0)
	{
		rotate_both_stacks(a, b);
		index_in_a--;
		index_in_b--;
	}
	if (index_in_a == 0)
		while (index_in_b-- > 0)
			rotate_one_stack(b, 1);
	else
		while (index_in_a-- > 0)
			rotate_one_stack(a, 1);
	push(b, a);
}

void	rrr_push(t_stack *a, t_stack *b, t_node *node)
{
	int	index_in_b;
	int	index_in_a;

	index_in_a = node->index;
	index_in_b = find_biggest_lower(b, node->value);
	while (index_in_a < a->len && index_in_b < b->len)
	{
		reverse_rotate_both_stacks(a, b);
		index_in_a++;
		index_in_b++;
	}
	if (index_in_a == a->len)
		while (index_in_b++ != b->len)
			reverse_rotate_one_stack(b, 1);
	else
		while (index_in_a++ != a->len)
			reverse_rotate_one_stack(a, 1);
	push(b, a);
}

void	easy_push(t_stack *a, t_stack *b, t_node *node)
{
	int	index_in_b;

	index_in_b = find_biggest_lower(b, node->value);
	if (a->len / 2 >= node->index)
		while (node->index != 0)
			rotate_one_stack(a, 1);
	else
		while (node->index != 0)
			reverse_rotate_one_stack(a, 1);
	if (b->len / 2 >= index_in_b)
		while (index_in_b-- != 0)
			rotate_one_stack(b, 1);
	else
		while (index_in_b++ != b->len)
			reverse_rotate_one_stack(b, 1);
	push(b, a);
}

void	move_to_second_stack(t_stack *a, t_stack *b, t_node *node)
{
	int	cond;

	cond = count_operations(a, b, node).variant;
	if (cond == 3)
		easy_push(a, b, node);
	else if (cond == 1)
		rr_push(a, b, node);
	else if (cond == 2)
		rrr_push(a, b, node);
}
