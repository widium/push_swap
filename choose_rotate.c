/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:22:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/20 17:56:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_rotate_max(t_stack **A)
{
	int		value;
	t_node	*iter;
	t_node	*max;
	t_node	*middle;

	iter = (*A)->bot;
	middle = get_middle(A);
	max = get_max(A);
	while (!(is_max(A, (*A)->top->value)))
	{
		if (get_index(A, max->value) < get_index(A, middle->value))
			reverse_rotate_b(A);
		else
			rotate_b(A);
	}
}

void	choose_rotate_min(t_stack **A)
{
	int		value;
	t_node	*top;
	t_node	*min;
	t_node	*middle;

	top = (*A)->top;
	while (!(is_min(A, top->value)))
	{
		middle = get_middle(A);
		min = get_min(A);
		if (get_index(A, min->value) < get_index(A, middle->value))
			reverse_rotate_a(A);
		else
			rotate_a(A);
		top = (*A)->top;
	}
}

void	choose_rotate_group(t_stack **A, int group)
{
	int		value;
	t_node	*middle;
	t_node	*top;

	top = (*A)->top;
	while ((*A)->top->value > group)
	{
		middle = get_middle(A);
		if (index_of_shortest_candidate(A, group) < get_index(A, middle->value))
			reverse_rotate_a(A);
		else
			rotate_a(A);
		top = (*A)->top;
	}
}
