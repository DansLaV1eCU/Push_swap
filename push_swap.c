/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/27 23:30:46 by danslav1e        ###   ########.fr       */
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
    return (1);
}

int main(int argc, char** argv)
{
    stack stack_a = {0};
//    stack stack_b = {0};

    if (argc == 1)
        return (0);
    if (!check_parameters(argc, argv, &stack_a))
    {   
        free_stack(&stack_a);
        printf("Error\n");
        return (0);
    }
    else
    {
        while (stack_a.start)
        {
            printf("%ld\n",stack_a.start->value);
            stack_a.start = stack_a.start->next;
        }
        printf("Norm\n");
    }
        
    return (0);
}
