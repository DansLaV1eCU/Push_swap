/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/01 04:15:48 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_count = 0;

void swap_one_stack(stack *s, int p)
{
    t_node *temp;

    if (s->len <= 1)
        return ;
    if (s->len == 2)
    {
        temp = s->start;
        s->end->next = temp;
        s->end->prev = NULL;
        s->start = s->end;
        s->start->index = 0;
        temp->prev = s->start;
        temp->next = NULL;
        s->end = temp;
        s->end->index = 1;
    }
    else
    {
        s->start->prev = s->start->next;
        s->start->next = s->start->prev->next;
        s->start->next->prev = s->start;
        s->start->index = 1;
        s->start->prev->next = s->start;
        s->start->prev->prev = NULL;
        s->start = s->start->prev;
        s->start->index = 0;
    }
    if (p)
    {
        ft_printf("s%c\n", s->name);
        g_count++;
    }
}

void swap_both_stacks(stack *s1, stack *s2)
{
    swap_one_stack(s1, 0);
    swap_one_stack(s2, 0);
    g_count+=2;
    ft_printf("ss\n");
}

void push(stack *s1, stack *s2)
{
    t_node *temp;

    if (s2->len == 0)
        return ;
    s2->len--;
    temp = s2->start;
    s2->start = s2->start->next;
    if (s1->len == 0)
    {
        lstadd_back(s1, temp);
        s1->start->next = NULL;
    }
    else
    {
        s1->start->prev = temp;
        temp->next = s1->start;
        s1->start = temp;
        s1->len++;
    }
    if (s2->start)
            s2->start->prev = NULL;
    if (s2->len != 0)
        s2->start->prev = NULL;
    else
        s2->end = NULL;
    change_index(s1, 1);
    s1->start->index = 0;
    change_index(s2, -1);
    g_count++;
    ft_printf("p%c\n", s1->name);
}

void change_index(stack *s, int m)
{
    t_node *temp;

    temp = s->start;
    while (temp)
    {
        temp->index += m;
        temp = temp->next;
    }
}

void rotate_one_stack(stack *s, int p)
{
    if (s->len <= 1)
        return ;
    s->end->next = s->start;
    s->start->prev = s->end;
    s->start = s->start->next;
    s->start->prev = NULL;
    s->end = s->end->next;
    s->end->next = NULL;
    change_index(s, -1);
    s->end->index = s->len - 1;
    if (p)
    {
        g_count++;
        ft_printf("r%c\n", s->name);
    }
}

void rotate_both_stacks(stack *s1, stack *s2)
{
    rotate_one_stack(s1, 0);
    rotate_one_stack(s2, 0);
    g_count+=2;
    ft_printf("rr\n");
}

void reverse_rotate_one_stack(stack *s, int p)
{
    if (s->len <= 1)
        return ;
    s->start->prev = s->end;
    s->end->next = s->start;
    s->end = s->end->prev;
    s->end->next = NULL;
    s->start = s->start->prev;
    s->start->prev = NULL;
    change_index(s, 1);
    s->start->index = 0;
    if (p)
    {
        g_count++;
        ft_printf("rr%c\n", s->name);
    }
}

void reverse_rotate_both_stacks(stack *s1, stack *s2)
{
    reverse_rotate_one_stack(s1, 0);
    reverse_rotate_one_stack(s2, 0);
    g_count+=2;
    ft_printf("rrr\n");
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
    // print_stack(a);
    // ft_printf("\n");
    // print_stack(b);
    // exit(0);
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

    stack_a.name = 'a';
    stack_b.name = 'b';
    if (argc == 1 || stack_b.len)
        return (0);
    if (!check_parameters(argc, argv, &stack_a))
    {   
        free_stack(&stack_a);
        write(2, "Error\n", 6);
        return (0);
    }
    else
    {
        // ft_printf("here");
        stack_a.len = stack_a.end->index + 1;
        push_swap(&stack_a, &stack_b);
        // print_stack(&stack_a);
        // ft_printf("\n");
        // print_stack(&stack_b);
        // ft_printf("%d\n",g_count);
        free_stack(&stack_a);
    }
    return (0);
}
