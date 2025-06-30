/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_free_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/30 18:32:30 by danslav1e        ###   ########.fr       */
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

void free_stack(stack *a)
{
    t_node *temp;
    t_node *move;

    temp = a->start;
    while (temp)
    {
        move = temp;
        temp = temp->next;
        free(move);
    }
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