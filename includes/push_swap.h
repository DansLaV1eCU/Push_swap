/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:14:14 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/08 20:00:28 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	long			value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				len;
	char			name;
	t_node			*start;
	t_node			*end;
}					t_stack;

typedef struct s_two_ints
{
	int				count;
	int				variant;
}					t_two_ints;

// add_free_stack
int					check_dublicates(t_stack *stack_a);
int					check_parameters(int len, char **s, t_stack *stack_a);
void				free_stack(t_stack *a);
int					is_sorted(t_stack *a);
int					free_split(char **str);

// push_swap
void				push_swap(t_stack *a, t_stack *b);

// move_cheapest
void				rr_push(t_stack *a, t_stack *b, t_node *node);
void				rrr_push(t_stack *a, t_stack *b, t_node *node);
void				easy_push(t_stack *a, t_stack *b, t_node *node);
void				move_to_second_stack(t_stack *a, t_stack *b, t_node *node);

// operations1
void				swap_one_stack(t_stack *s, int p);
void				swap_both_stacks(t_stack *s1, t_stack *s2);
void				push(t_stack *s1, t_stack *s2);
void				change_index(t_stack *s, int m);

// operations2
void				rotate_one_stack(t_stack *s, int p);
void				rotate_both_stacks(t_stack *s1, t_stack *s2);
void				reverse_rotate_one_stack(t_stack *s, int p);
void				reverse_rotate_both_stacks(t_stack *s1, t_stack *s2);

// find_cheapest
int					find_biggest_lower(t_stack *b, int value);
int					find_lowest_bigger(t_stack *b, int value);
t_two_ints			min_of_three(int a, int b, int c);
t_two_ints			count_operations(t_stack *a, t_stack *b, t_node *node);
t_node				*find_cheapest(t_stack *a, t_stack *b);

// sort_utils
int					find_min(t_stack *a);
int					find_max(t_stack *a);
void				sort_three_items_stack(t_stack *a);
void				rotate_first(t_stack *a, t_node *node);
void				rotate_to_min_at_top(t_stack *a);

// utils
t_node				*node_new(long value);
void				lstadd_back(t_stack *stack_a, t_node *new);
long				push_atoi(char *str);
void				print_stack(t_stack *s);

// split
void				*clean1(char **res, int count);
int					count_words1(const char *s);
char				*get_next_word1(const char **s);
char				**split(const char *s);

#endif
