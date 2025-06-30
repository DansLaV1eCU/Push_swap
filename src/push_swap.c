/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/30 18:41:05 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(stack *a, stack *b)
{
    if (a->len <= 3)
    {
        sort_small_stack(a);
        free_stack(a);
        return ;
    }
    push(b,a);
    push(b,a);
    while (a->len > 3)
        move_to_second_stack(a, b, find_cheapest(a,b));
    sort_small_stack(a);
    while (b->len > 0)
    {
        rotate_first(a,b->start);
        push(a,b);
    }
    rotate_to_min_at_top(a);
    free_stack(a);
}

int main(int argc, char** argv)
{
    stack stack_a = {0};
    stack stack_b = {0};

    if (argc == 1 || stack_b.len)
        return (0);
    if (!check_parameters(argc, argv, &stack_a))
    {   
        free_stack(&stack_a);
        printf("Error\n");
        return (0);
    }
    else
    {
        print_stack(&stack_a);
    }
    return (0);
}
