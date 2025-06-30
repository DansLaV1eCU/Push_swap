/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:14:14 by danslav1e         #+#    #+#             */
/*   Updated: 2025/06/30 19:17:31 by danslav1e        ###   ########.fr       */
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

// add_free_stack
int check_dublicates(stack *stack_a);
int check_parameters(int len, char** s, stack *stack_a);
void free_stack(stack *a);
void print_stack(stack *s);

// push_swap
void push_swap(stack *a, stack *b);

// move_cheapest
void rr_push(stack *a, stack *b, t_node *node);
void rrr_push(stack *a, stack *b, t_node *node);
void easy_push(stack *a, stack *b, t_node *node);
void move_to_second_stack(stack *a, stack *b, t_node *node);

// operations1
void swap_one_stack(stack *s, int p);
void swap_both_stacks(stack *s1, stack *s2);
void push(stack *s1, stack *s2);
void change_index(stack *s, int m);

// operations2
void rotate_one_stack(stack *s, int p);
void rotate_both_stacks(stack *s1, stack *s2);
void reverse_rotate_one_stack(stack *s, int p);
void reverse_rotate_both_stacks(stack *s1, stack *s2);

// find_cheapest
int find_biggest_lower(stack *b, int value);
t_two_ints min_of_three(int a, int b, int c);
t_two_ints count_operations(stack *a, stack *b, t_node *node);
t_node *find_cheapest(stack *a, stack *b);

// sort_utils
int find_min(stack *a);
void sort_small_stack(stack *a);
void rotate_first(stack *a, t_node *node);
void rotate_to_min_at_top(stack *a);

// utils
t_node *node_new(long value);
void lstadd_back(stack *stack_a, t_node* new);
void free_stack(stack* s);
long	push_atoi(char *str);

#endif
