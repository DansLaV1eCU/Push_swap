/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_free_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:02:51 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/08 20:38:01 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dublicates(t_stack *stack_a)
{
	t_node	*move;
	t_node	*current;

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

int	check_parameters(int len, char **s, t_stack *stack_a)
{
	long	value;
	int		count;
	int		i;
	char	**str;

	count = 1;
	while (count < len)
	{
		str = split(s[count++]);
		if (!str || !*str)
			return (free_split(str));
		i = -1;
		while (str[++i])
		{
			value = push_atoi(str[i]);
			if (value > 2147483647 || value < -2147483648)
				return (free_split(str));
			lstadd_back(stack_a, node_new(value));
		}
		free_split(str);
	}
	if (!check_dublicates(stack_a))
		return (0);
	return (1);
}

void	free_stack(t_stack *a)
{
	t_node	*temp;
	t_node	*move;

	temp = a->start;
	while (temp)
	{
		move = temp;
		temp = temp->next;
		free(move);
	}
}

int	is_sorted(t_stack *a)
{
	int		flag;
	t_node	*temp;

	flag = 0;
	temp = a->start;
	while (temp)
	{
		if (temp->next)
			if (temp->value > temp->next->value)
				flag++;
		temp = temp->next;
	}
	if (flag == 0)
		return (1);
	if (a->end > a->start)
		flag++;
	if (flag == 1)
	{
		rotate_to_min_at_top(a);
		return (1);
	}
	else
		return (0);
}

int	free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (0);
}
