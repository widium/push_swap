/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:26:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_group_to_b(t_stack **A, t_stack **B, int group, int size_group)
{
	t_node	*top;
	int		size;

	while (smaller_than_groups(A, group))
	{
		size = (*A)->size;
		top = (*A)->top;
		if (top->value <= group)
			push_b(A, B);
		if (!(smaller_than_groups(A, group)))
			group += size_group;
		else
			choose_rotate_group(A, group);
	}
}

void	push_max_b_to_a(t_stack **A, t_stack **B)
{
	while ((*B)->top)
	{
		if (is_max(B, (*B)->top->value))
			push_a(A, B);
		else
			choose_rotate_max(B);
	}
}

void	sort_a(t_stack **A, t_stack **B)
{
	t_node	*iter;
	t_node	*top;
	t_node	*top_prev;
	int		size;

	if (!(*A)->top)
		return ;
	while (!(is_sorted(A)))
	{
		size = (*A)->size;
		top = (*A)->top;
		top_prev = top->prev;
		if (is_min(A, top->value) && size > 3)
			push_b(A, B);
		if (swap_min_max(A, top_prev, top))
			swap_a(A);
		choose_rotate_min(A);
	}
}
