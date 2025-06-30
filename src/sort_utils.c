/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:40:59 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/30 19:28:43 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(stack *a)
{
    t_node *temp;
    t_node *min;

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

void sort_small_stack(stack *a)
{
    if (a->len == 2)
    {
        if (a->start->value > a->end->value)
            swap_one_stack(a,1);
    }
    else if (a->len == 3)
    {
        if (a->start->value > a->start->next->value && a->end->value < a->end->prev->value)
        {
            swap_one_stack(a,1);
            reverse_rotate_one_stack(a,1);
        }
        else if (a->end->value < a->end->prev->value && a->start->value < a->end->value)
        {
            swap_one_stack(a,1);
            rotate_one_stack(a,1);
        }
        else if (find_min(a) == 1)
            rotate_one_stack(a,1);
        else
            reverse_rotate_one_stack(a,1);
    }
}

void rotate_first(stack *a, t_node *node)
{
    int index_in_a;

    index_in_a = find_biggest_lower(a, node->value);
    if (a->len / 2 >= index_in_a)
        while (index_in_a-- != 0)
            rotate_one_stack(a,1);
    else
        while (index_in_a++ != a->len)
            reverse_rotate_one_stack(a,1);
}

void rotate_to_min_at_top(stack *a)
{
    int index;

    index = find_min(a);
    if (a->len / 2 >= index)
        while (index-- != 0)
            rotate_one_stack(a,1);
    else
        while (index++ != a->len)
            reverse_rotate_one_stack(a,1);
}