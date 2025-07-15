/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:21:49 by danslav1e         #+#    #+#             */
/*   Updated: 2025/07/03 22:02:45 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gnl_checker(t_stack *a, t_stack *b)
{
	ssize_t	status;
	char	char_buff;
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_calloc(4, sizeof(char));
	if (!str)
		return (0);
	while (1)
	{
		status = read(0, &char_buff, 1);
		if (status == -1)
			return (0);
		if (status == 0)
			break ;
		str[i] = char_buff;
		if (i > 3)
		{
			free(str);
			return (0);
		}
		if (str[i] == '\n')
		{
			str[i] = '\0';
			i = 0;
			if (!operate_command(a, b, str))
				return (0);
		}
		i++;
	}
	if (str[0] && !operate_command(a, b, str))
		return (0);
	free(str);
	return (1);
}

int	operate_command(t_stack *a, t_stack *b, char *s)
{
	if (s == "sa")
		swap_one_stack(a, 0);
	else if (s == "sb")
		swap_one_stack(b, 0);
	else if (s == "ss")
		swap_both_stacks(a,b, 0);
	else if (s == "pa")
		push(a, b, 0);
	else if (s == "pb")
		push(b, a, 0);
	else if (s == "ra")
		rotate_one_stack(a, 0);
	else if (s == "rb")
		rotate_one_stack(b, 0);
	else if (s == "rr")
		rotate_both_stacks(a, b, 0);
	else if (s == "rra")
		reverse_rotate_one_stack(a, 0);
	else if (s == "rrb")
		reverse_rotate_one_stack(b, 0);
	else if (s == "rrr")
		reverse_rotate_both_stacks(a, b, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int flag;

	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	if (!check_parameters(argc, argv, &a))
		write_error(&a);
	a.len = a.end->index + 1;
	if (!gnl_checker(&a, &b))
		write_error(&a);
	if (is_sorted(&a) == 1 && b.len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	return (0);
}

void write_error(t_stack *a)
{
	free_stack(&a);
	write(2, "Error\n", 6);
	exit(1);
}