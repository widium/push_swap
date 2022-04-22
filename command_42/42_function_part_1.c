/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_function_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:53:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:17:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **A)
{
	t_node	*top_1;
	t_node	*top_2;
	t_node	*top_3;

	top_1 = (*A)->top;
	top_2 = (*A)->top->prev;
	top_3 = (*A)->top->prev->prev;
	if (!top_3)
	{
		rotate_a(A);
		return ;
	}
	(*A)->top = top_2;
	top_2->next = NULL;
	top_2->prev = top_1;
	top_1->next = top_2;
	top_1->prev = top_3;
	top_3->next = top_1;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack **B)
{
	t_node	*top_1;
	t_node	*top_2;
	t_node	*top_3;

	top_1 = (*B)->top;
	top_2 = (*B)->top->prev;
	top_3 = (*B)->top->prev->prev;
	(*B)->top = top_2;
	top_2->next = NULL;
	top_2->prev = top_1;
	top_1->next = top_2;
	top_1->prev = top_3;
	top_3->next = top_1;
	ft_putstr_fd("sb\n", 1);
}

void	reverse_rotate_a(t_stack **A)
{
	t_node	*top;
	t_node	*bot;
	t_node	*bot_next;

	top = (*A)->top;
	bot = (*A)->bot;
	bot_next = (*A)->bot->next;
	if (!bot_next)
		return ;
	bot->next = NULL;
	bot_next->prev = NULL;
	(*A)->bot = bot_next;
	top->next = bot;
	bot->prev = top;
	(*A)->top = bot;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack **B)
{
	t_node	*top;
	t_node	*bot;
	t_node	*bot_next;

	top = (*B)->top;
	bot = (*B)->bot;
	bot_next = (*B)->bot->next;
	if (!bot_next)
		return ;
	bot->next = NULL;
	bot_next->prev = NULL;
	(*B)->bot = bot_next;
	top->next = bot;
	bot->prev = top;
	(*B)->top = bot;
	ft_putstr_fd("rrb\n", 1);
}
