/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:14:14 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/27 23:30:56 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

typedef struct s_node
{
    long value;
    int index;
    struct s_node* next;
    struct s_node* prev;
} t_node;

typedef struct s_stack
{
    int len;
    t_node* start;
    t_node* end;
} stack;

t_node *node_new(long value);
void lstadd_back(stack *stack_a, t_node* new);
void free_stack(stack* s);
long	push_atoi(char *str);

#endif