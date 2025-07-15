/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/07 22:09:51 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
	{
		if (a->len == 3)
			sort_three_items_stack(a);
		else if (a->len == 2)
			if (a->start->value > a->end->value)
				swap_one_stack(a, 1);
		return ;
	}
	else if (is_sorted(a) == 1)
		return ;
	push(b, a, 1);
	push(b, a, 1);
	while (a->len > 3)
		move_to_second_stack(a, b, find_cheapest(a, b));
	sort_three_items_stack(a);
	while (b->len > 0)
	{
		rotate_first(a, b->start);
		push(a, b, 1);
	}
	rotate_to_min_at_top(a);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	stack_a.name = 'a';
	stack_b.name = 'b';
	if (argc == 1 || stack_b.len)
		return (0);
	if (!check_parameters(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	else
	{
		stack_a.len = stack_a.end->index + 1;
		push_swap(&stack_a, &stack_b);
		// print_stack(&stack_a);
		free_stack(&stack_a);
	}
	return (0);
}
