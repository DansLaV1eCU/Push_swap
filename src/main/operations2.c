/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:52:09 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/18 18:31:06 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one_stack(t_stack *s, int p)
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

void	rotate_both_stacks(t_stack *s1, t_stack *s2, int p)
{
	rotate_one_stack(s1, 0);
	rotate_one_stack(s2, 0);
	if (p)
		ft_printf("rr\n");
}

void	reverse_rotate_one_stack(t_stack *s, int p)
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

void	reverse_rotate_both_stacks(t_stack *s1, t_stack *s2, int p)
{
	reverse_rotate_one_stack(s1, 0);
	reverse_rotate_one_stack(s2, 0);
	if (p)
		ft_printf("rrr\n");
}
