/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:27:24 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/28 21:37:16 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_one_stack(stack *s, int p)
{
    if (s->len <= 1)
        return ;
    s->start->prev = s->start->next;
    s->start->next = s->start->prev->next;
    s->start->next->prev = s->start;
    s->start->index = 1;
    s->start->prev->next = s->start;
    s->start->prev->prev = NULL;
    s->start = s->start->prev;
    s->start->index = 0;
    if (s->len == 2)
        s->end = s->start->next;
    if (p)
        ft_printf("s%c\n", s->name);
}

void swap_both_stacks(stack *s1, stack *s2)
{
    swap_one_stack(s1, 0);
    swap_one_stack(s2, 0);
    ft_printf("ss\n");
}

void push(stack *s1, stack *s2)
{
    if (s2->len == 0)
        return ;
    s2->len--;
    s1->len++;
    s1->start->prev = s2->start;
    s2->start = s2->start->next;
    s1->start->prev->next = s1->start;
    if (s2->len != 0)
        s2->start->prev = NULL;
    else
        s2->end = NULL;
    change_index(s1, 1);
    s1->start->index = 0;
    change_index(s2, -1);
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
        ft_printf("r%c\n", s->name);
}

void rotate_both_stacks(stack *s1, stack *s2)
{
    rotate_one_stack(s1, 0);
    rotate_one_stack(s2, 0);
    ft_printf("rr");
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
        ft_printf("rr%c\n", s->name);
}

void reverse_rotate_both_stacks(stack *s1, stack *s2)
{
    reverse_rotate_one_stack(s1, 0);
    reverse_rotate_one_stack(s2, 0);
    ft_printf("rrr");
}

