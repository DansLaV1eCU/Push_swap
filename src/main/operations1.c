/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:27:24 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/18 18:31:13 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one_stack(t_stack *s, int p)
{
	if (s->len <= 1)
		return ;
	if (s->len == 2)
	{
		s->start->prev = s->end;
		s->start->next = NULL;
		s->end->next = s->start;
		s->end->prev = NULL;
		s->end = s->start;
		s->start = s->end->prev;
	}
	else
	{
		s->start->prev = s->start->next;
		s->start->next = s->start->prev->next;
		s->start->next->prev = s->start;
		s->start->prev->next = s->start;
		s->start->prev->prev = NULL;
		s->start = s->start->prev;
	}
	s->start->index = 0;
	s->start->next->index = 1;
	if (p)
		ft_printf("s%c\n", s->name);
}

void	swap_both_stacks(t_stack *s1, t_stack *s2, int p)
{
	swap_one_stack(s1, 0);
	swap_one_stack(s2, 0);
	if (p)
		ft_printf("ss\n");
}

void	push(t_stack *s1, t_stack *s2, int p)
{
	t_node	*temp;

	s2->len--;
	temp = s2->start;
	s2->start = s2->start->next;
	if (s1->len == 0)
		lstadd_back(s1, temp);
	else
	{
		s1->start->prev = temp;
		temp->next = s1->start;
		s1->start = temp;
		s1->len++;
	}
	if (s2->start || s2->len != 0)
		s2->start->prev = NULL;
	else if (s2->len != 0)
		s2->end = NULL;
	change_index(s1, 1);
	s1->start->index = 0;
	change_index(s2, -1);
	if (p)
		ft_printf("p%c\n", s1->name);
}

void	change_index(t_stack *s, int m)
{
	t_node	*temp;

	temp = s->start;
	while (temp)
	{
		temp->index += m;
		temp = temp->next;
	}
}
