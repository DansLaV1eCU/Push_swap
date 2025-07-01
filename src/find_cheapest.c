/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:35:43 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/01 03:32:24 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest_lower(stack *b, int value)
{
    t_node *biggest_lower_node;
    t_node *temp;

    temp = b->start;
    biggest_lower_node = NULL;
    while (temp)
    {
        if (temp->value < value && (!biggest_lower_node || temp->value > biggest_lower_node->value))
            biggest_lower_node = temp;
        temp = temp->next;
    }
    if (biggest_lower_node == NULL)
        return (find_max(b));
    return (biggest_lower_node->index);
}

int find_lowest_bigger(stack *a, int value)
{
    t_node *lowest_bigger_node;
    t_node *temp;

    temp = a->start;
    lowest_bigger_node = NULL;
    while (temp)
    {
        if (temp->value > value &&  (!lowest_bigger_node || temp->value < lowest_bigger_node->value))
            lowest_bigger_node = temp;
        temp = temp->next;
    }
    if (lowest_bigger_node == NULL)
        return (find_min(a));
    return (lowest_bigger_node->index);
}

t_two_ints min_of_three(int a, int b, int c)
{
    t_two_ints t;

    if (c <= a && c <= b)
    {
        t.count = c;
        t.variant = 3;
    }
    else if (a <= b && a <= c)
    {
        t.count = a;
        t.variant = 1;
    }
    else if (b <= a && b <= c)
    {
        t.count = b;
        t.variant = 2;
    }
    return (t);
}

t_two_ints count_operations(stack *a, stack *b, t_node *node)
{
    int index_in_b;
    int both_up;
    int both_down;
    int easy_way;

    easy_way = 1;
    index_in_b = find_biggest_lower(b, node->value);
    // ft_printf("Number in a %d - index in a %d | index in b %d", node->value, node->index, index_in_b);
    if (node->index > index_in_b)
        both_up = node->index + 1;
    else
        both_up = index_in_b + 1;
    if (a->len - node->index > b->len - index_in_b)
        both_down = a->len - node->index + 1;
    else
        both_down = b->len - index_in_b + 1;
    if (a->len / 2 >= node->index)
        easy_way += node->index;
    else
        easy_way += a->len - node->index;
    if (b->len / 2 >= index_in_b)
        easy_way += index_in_b;
    else
        easy_way += b->len - index_in_b;
    // ft_printf("easy - %d | up - %d | down - %d\n", easy_way, both_up, both_down);
    return (min_of_three(both_up, both_down, easy_way));
}

t_node *find_cheapest(stack *a, stack *b)
{
    t_node *temp;
    t_node *cheapest;
    int min;
    t_two_ints t;

    temp = a->start;
    cheapest = NULL;
    min = 0;
    while (temp)
    {
        t = count_operations(a, b, temp);
        if (!cheapest || t.count < min)
        {
            min = t.count;
            cheapest = temp;
        }
        temp = temp->next;
    }
    return (cheapest);
}