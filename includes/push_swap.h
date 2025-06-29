/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:14:14 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/29 19:33:14 by danslav1e        ###   ########.fr       */
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
    char name;
    t_node* start;
    t_node* end;
} stack;

typedef struct s_two_ints
{
    int count;
    int variant;
} t_two_ints;

t_node *node_new(long value);
void lstadd_back(stack *stack_a, t_node* new);
void free_stack(stack* s);
long	push_atoi(char *str);

void swap_one_stack(stack *s, int p);
void swap_both_stacks(stack *s1, stack *s2);
void push(stack *s1, stack *s2);
void rotate_one_stack(stack *s, int p);
void rotate_both_stacks(stack *s1, stack *s2);
void reverse_rotate_one_stack(stack *s, int p);
void reverse_rotate_both_stacks(stack *s1, stack *s2);
void change_index(stack *s, int m);

#endif