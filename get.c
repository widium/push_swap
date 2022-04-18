/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:11:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/18 11:38:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_middle(t_stack **A)
{
	int		size;
	int		i;
	int		middle_value;
	t_node	*iter;

	i = 0;
	iter = (*A)->bot;
	if (!iter)
		return (NULL);
	size = (*A)->size;
	middle_value = size / 2;
	while (iter)
	{
		if (i == middle_value)
			return (iter);
		i++;
		iter = iter->next;
	}
	return (NULL);
}

t_node	*get_max(t_stack **A)
{
	int		curr_value;
	int		i;
	int		size;
	t_node	*iter;
	t_node	*iter2;

	i = 0;
	size = (*A)->size;
	iter2 = (*A)->bot;
	iter = (*A)->bot;
	if (!iter)
		return (NULL);
	while (i < (size + 1))
	{
		curr_value = iter->value;
		if (is_max(A, curr_value))
			return (iter);
		i++;
		if (i < size)
			iter = iter->next;
	}
	return (NULL);
}

t_node	*get_min(t_stack **A)
{
	int		curr_value;
	int		i;
	int		size;
	t_node	*iter;
	t_node	*iter2;

	size = (*A)->size;
	iter2 = (*A)->bot;
	iter = (*A)->bot;
	i = 0;
	if (size == 1)
		return ((*A)->bot);
	while (i < (size + 1))
	{
		curr_value = iter->value;
		if (is_min(A, curr_value))
			return (iter);
		i++;
		if (i < size)
			iter = iter->next;
	}
	return (NULL);
}

int	get_index(t_stack **A, int value)
{
	int		curr_value;
	int		i;
	t_node	*iter;

	i = 0;
	iter = (*A)->bot;
	while (iter)
	{
		curr_value = iter->value;
		if (value == curr_value)
			return (i);
		i++;
		iter = iter->next;
	}
	return (-1);
}

int	index_of_shortest_candidate(t_stack **A, int group)
{
	int		value;
	t_node	*iter;

	iter = (*A)->top;
	while (iter)
	{
		value = iter->value;
		if (value < group)
			return (get_index(A, value));
		iter = iter->prev;
	}
	return (0);
}
