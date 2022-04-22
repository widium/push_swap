/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:58:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:29:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	larger_than_groups(t_stack **A, int group)
{
	int		value;
	t_node	*iter;

	iter = (*A)->bot;
	while (iter)
	{
		value = iter->value;
		if (value >= group)
			return (1);
		iter = iter->next;
	}
	return (0);
}

int	smaller_than_groups(t_stack **A, int group)
{
	int		value;
	t_node	*iter;

	iter = (*A)->bot;
	while (iter)
	{
		value = iter->value;
		if (value <= group)
			return (1);
		iter = iter->next;
	}
	return (0);
}

int	is_min(t_stack **B, int value)
{
	int		size;
	int		i;
	t_node	*min;
	t_node	*iter;

	size = (*B)->size;
	i = 0;
	min = (*B)->bot;
	iter = (*B)->bot;
	if (!(*B)->top)
		return (0);
	while (i < (size + 1))
	{
		if (iter->value < min->value)
			min = iter;
		i++;
		if (i < size)
			iter = iter->next;
	}
	if (min->value == value)
		return (1);
	return (0);
}

int	is_max(t_stack **A, int value)
{
	int		i;
	int		size;
	t_node	*iter;
	t_node	*max;

	i = 0;
	size = (*A)->size;
	max = (*A)->bot;
	iter = (*A)->bot;
	while (i < (size + 1))
	{
		if (iter->value > max->value)
			max = iter;
		i++;
		if (i < size)
			iter = iter->next;
	}
	if (max->value == value)
		return (1);
	return (0);
}
