// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   operations1.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/06/28 19:27:24 by danslav1e         #+#    #+#             */
// /*   Updated: 2025/07/01 01:17:32 by danslav1e        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void swap_one_stack(stack *s, int p)
// {
//     t_node *temp;

//     if (s->len <= 1)
//         return ;
//     if (s->len == 2)
//     {
//         temp = s->start;
//         s->end->next = temp;
//         s->end->prev = NULL;
//         s->start = s->end;
//         s->start->index = 0;
//         temp->prev = s->start;
//         temp->next = NULL;
//         s->end = temp;
//         s->end->index = 1;
//     }
//     else
//     {
//         s->start->prev = s->start->next;
//         s->start->next = s->start->prev->next;
//         s->start->next->prev = s->start;
//         s->start->index = 1;
//         s->start->prev->next = s->start;
//         s->start->prev->prev = NULL;
//         s->start = s->start->prev;
//         s->start->index = 0;
//     }
//     if (p)
//     {
//         ft_printf("s%c\n", s->name);
//         g_count++;
//     }
// }

// void swap_both_stacks(stack *s1, stack *s2)
// {
//     swap_one_stack(s1, 0);
//     swap_one_stack(s2, 0);
//     g_count+=2;
//     ft_printf("ss\n");
// }

// void push(stack *s1, stack *s2)
// {
//     t_node *temp;

//     if (s2->len == 0)
//         return ;
//     s2->len--;
//     temp = s2->start;
//     s2->start = s2->start->next;
//     if (s1->len == 0)
//     {
//         lstadd_back(s1, temp);
//         s1->start->next = NULL;
//     }
//     else
//     {
//         s1->start->prev = temp;
//         temp->next = s1->start;
//         s1->start = temp;
//         s1->len++;
//     }
//     if (s2->start)
//             s2->start->prev = NULL;
//     if (s2->len != 0)
//         s2->start->prev = NULL;
//     else
//         s2->end = NULL;
//     change_index(s1, 1);
//     s1->start->index = 0;
//     change_index(s2, -1);
//     g_count++;
//     ft_printf("p%c\n", s1->name);
// }

// void change_index(stack *s, int m)
// {
//     t_node *temp;

//     temp = s->start;
//     while (temp)
//     {
//         temp->index += m;
//         temp = temp->next;
//     }
// }
