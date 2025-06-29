/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/29 23:37:48 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_dublicates(stack *stack_a)
{
    t_node *move;
    t_node *current;

    current = stack_a->start;
    move = current->next;
    while (current->next)
    {
        while (move)
        {
            if (current->value == move->value)
                return (0);
            move = move->next;
        }
        current = current->next;
        move = current->next;
    }
    return (1);
}

int check_parameters(int len, char** s, stack *stack_a)
{
    long value;
    int count;
    t_node *temp;

    count = 1;
    while (count < len)
    {
        if (ft_strncmp(s[count],"0",2) == 0)
            value = 0;
        else
        {
            value = push_atoi(s[count]);
            if (value == 0 || value > 2147483647 || value < -2147483648)
                return (0);
        }
        lstadd_back(stack_a, node_new(value));
        count++;
    }
    if (!check_dublicates(stack_a))
        return (0);
    temp = stack_a->start;
    while (temp->next)
        temp = temp->next;
    stack_a->end = temp;
    return (1);
}

void print_stack(stack *s)
{
    t_node *temp;

    ft_printf("Stack %c - length %d\n", s->name, s->len);
    ft_printf("Start value %d - start index %d\n", s->start->value, s->start->index);
    ft_printf("End value %d - end index %d\n\n", s->end->value, s->end->index);
    temp = s->start;
    while (temp)
    {
        ft_printf("Index: %d - Value: %d\n", temp->index, temp->value);
        temp = temp->next;
    }
}

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
        if (a->start->value > a->end->value)
            swap_one_stack(a,1);
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

int find_biggest_lower(stack *b, int value)
{
    t_node *biggest_lower_node;
    t_node *temp;

    temp = b->start;
    biggest_lower_node = b->start;
    while (temp)
    {
        if (temp->value < value && temp->value > biggest_lower_node->value)
            biggest_lower_node = temp;
        temp = temp->next;
    }
    return (biggest_lower_node->index);
}

t_two_ints min_of_three(int a, int b, int c)
{
    t_two_ints t;
    if (a <= b && a <= c)
    {
        t.count = a;
        t.variant = 1;
    }
    else if (b <= a && b <= c)
    {
        t.count = b;
        t.variant = 2;
    }
    else if (c <= a && c <= b)
    {
        t.count = c;
        t.variant = 3;
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
    if (node->index > index_in_b)
        both_up = node->index + 1;
    else
        both_up = index_in_b + 1;
    if (a->len - node->index > b->len - index_in_b)
        both_down = node->index + 1;
    else
        both_down = index_in_b + 1;
    if (a->len / 2 >= node->index)
        easy_way += node->index;
    else
        easy_way += a->len - node->index;
    if (b->len / 2 >= index_in_b)
        easy_way += index_in_b;
    else
        easy_way += b->len - index_in_b;
    return (min_of_three(both_up, both_down, easy_way));
}

t_node *find_cheapest(stack *a, stack *b)
{
    t_node *temp;
    t_node *cheapest;
    int min;
    t_two_ints t;

    temp = a->start;
    cheapest = a->start;
    min = 0;
    while (temp)
    {
        t = count_operations(a, b, temp);
        if (t.count < min)
        {
            min = t.count;
            cheapest = temp;
        }
        temp = temp->next;
    }
    return (cheapest);
}

void rr_push(stack *a, stack *b, t_node *node)
{
    int index_in_b;
    int index_in_a;
    int count;

    index_in_b = find_biggest_lower(b, node);
    index_in_a = node->index;
    while (index_in_a-- > 0 && index_in_b-- > 0)
        rotate_both_stacks(a,b);
    if (index_in_a == 0)
        while (index_in_b-- > 0)
            rotate_one_stack(b,1);
    else    
        while (index_in_a-- > 0)
            rotate_one_stack(a,1);
    push(b,a);
}

void rrr_push(stack *a, stack *b, t_node *node)
{
    int index_in_b;
    int index_in_a;
    int count;

    index_in_a = node->index;
    index_in_b = find_biggest_lower(b, node);
    while (index_in_a != a->len && index_in_b != b->len)
    {
        reverse_rotate_both_stacks(a,b);
        index_in_a++;
        index_in_b++;
    }
    if (index_in_a == a->len)
        while (index_in_b++ != b->len)
            reverse_rotate_one_stack(b,1);
    else    
        while (index_in_a++ != a->len)
            reverse_rotate_one_stack(a,1);
    push(b,a);
}

void easy_push(stack *a, stack *b, t_node *node)
{
    int index_in_b;

    index_in_b = find_biggest_lower(b, node);
    if (a->len / 2 >= node->index)
        while (node->index != 0)
            rotate_one_stack(a,1);
    else
        while (node->index != 0)
            reverse_rotate_one_stack(a,1);
    if (b->len / 2 >= index_in_b)
        while (index_in_b-- != 0)
            rotate_one_stack(b,1);
    else
        while (index_in_b++ != b->len)
            reverse_rotate_one_stack(b,1);
    push(b,a);
}

void move_to_second_stack(stack *a, stack *b, t_node *node)
{
    int cond;

    cond = count_operations(a,b,node).variant;
    if (cond == 1)
        rr_push(a, b, node);
    if (cond == 2)
        rrr_push(a, b, node);
    if (cond == 3)
        easy_push(a, b, node);
}

void push_swap(stack *a, stack *b)
{
    if (a->len <= 3)
    {
        sort_small_stack(a);
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
