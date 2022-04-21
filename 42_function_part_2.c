/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_function_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:46:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/21 11:30:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **A, t_stack **B)
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*top_a_before;

	top_a = (*A)->top;
	top_b = (*B)->top;
	if (!top_a)
		return ;
	top_a_before = (*A)->top->prev;
	if (!top_a_before)
		set_stack_null(*A);
	else
	{
		top_a_before->next = NULL;
		(*A)->top = top_a_before;
	}
	top_a->prev = NULL;
	(*A)->size--;
	if (!top_b)
		(*B)->bot = top_a;
	else
		connect_node(top_b, top_a);
	(*B)->top = top_a;
	(*B)->size++;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_stack **A, t_stack **B)
{
	t_node	*top_b;
	t_node	*top_a;
	t_node	*top_b_before;

	top_b = (*B)->top;
	top_a = (*A)->top;
	if (!top_b)
		return ;
	top_b_before = (*B)->top->prev;
	if (!top_b_before)
		set_stack_null(*B);
	else
	{
		top_b_before->next = NULL;
		(*B)->top = top_b_before;
	}
	top_b->prev = NULL;
	(*B)->size--;
	if (!top_a)
		(*A)->bot = top_b;
	else
		connect_node(top_a, top_b);
	(*A)->top = top_b;
	(*A)->size++;
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_stack **A)
{
	t_node	*top;
	t_node	*top_prev;
	t_node	*bot;

	top = (*A)->top;
	top_prev = (*A)->top->prev;
	bot = (*A)->bot;
	if (!top_prev)
		return ;
	top->prev = NULL;
	top_prev->next = NULL;
	(*A)->top = top_prev;
	bot->prev = top;
	top->next = bot;
	(*A)->bot = top;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **B)
{
	t_node	*top;
	t_node	*top_prev;
	t_node	*bot;

	top = (*B)->top;
	top_prev = (*B)->top->prev;
	bot = (*B)->bot;
	if (!top_prev)
		return ;
	top->prev = NULL;
	top_prev->next = NULL;
	(*B)->top = top_prev;
	top->next = bot;
	bot->prev = top;
	(*B)->bot = top;
	ft_putstr_fd("rb\n", 1);
}
