/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 16:08:17 by ebennace         ###   ########.fr       */
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
	if ((*A)->size < 4)
	{
		sort_fast(A, B);
		return ;
	}
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

void	sort_fast(t_stack **A, t_stack **B)
{
	int	index_max;
	int	index_mid;
	int	index_min;

	while (!(is_sorted(A)))
	{
		if ((*A)->size > 2)
		{
			index_max = get_index(A, get_max(A)->value);
			index_mid = get_index(A, get_middle_node(A)->value);
			index_min = get_index(A, get_min(A)->value);
			choose_faster(A, index_min, index_mid, index_max);
		}	
		else
			choose_rotate_min(A);
	}
}

void	choose_faster(t_stack **A, int index_min, int index_mid, int index_max)
{
	if (index_mid > index_min && index_min > index_max)
		swap_a(A);
	else if (index_mid > index_max && index_max > index_min)
		reverse_rotate_a(A);
	else if (index_min > index_max && index_max > index_mid)
	{
		reverse_rotate_a(A);
		swap_a(A);
	}
	else if (index_max > index_mid && index_mid > index_min)
	{
		rotate_a(A);
		swap_a(A);
	}
	else
	{
		swap_a(A);
		reverse_rotate_a(A);
		swap_a(A);
	}
}
