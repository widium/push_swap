/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:36:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/18 11:03:55 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_type_of_split(t_stack **A, t_stack **B)
{
	int	size;

	size = (*A)->size;
	if (size <= 10)
		split_stack_mean(A, B);
	else
		split_stack_group(A, B);
}

void	split_stack_mean(t_stack **A, t_stack **B)
{
	int		size;
	int		group;
	t_node	*top;

	size = (*A)->size;
	group = get_mean(A);
	while (smaller_than_groups(A, group))
	{
		top = (*A)->top;
		if (top->value <= group)
			push_b(A, B);
		else
			choose_rotate_group(A, group);
	}
}

void	split_stack_group(t_stack **A, t_stack **B)
{
	int		size;
	int		group;
	int		size_group;
	int		range;

	size = (*A)->size;
	size_group = create_size_group(A);
	range = get_range(A);
	group = size_group;
	push_group_to_b(A, B, group, size_group);
}

int	create_size_group(t_stack **A)
{
	int	sqrt;
	int	size_group;
	int	range;
	int	size;

	size = (*A)->size;
	sqrt = get_sqrt(size);
	range = get_range(A);
	size_group = range / sqrt;
	return (size_group);
}
