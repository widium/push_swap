/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:48:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:24:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_sqrt(int nbr)
{
	int	sqrt;

	if (nbr < 0)
		return (0);
	sqrt = 0;
	while (sqrt * sqrt < nbr)
	{
		sqrt++;
		if (sqrt * sqrt == nbr)
			return (sqrt / 1.5);
	}
	return (sqrt / 1.5);
}

int	get_mean(t_stack **A)
{
	int		sum;
	int		size;
	int		curr_value;
	t_node	*iter;

	iter = (*A)->bot;
	size = (*A)->size;
	sum = 0;
	while (iter)
	{
		curr_value = iter->value;
		sum += curr_value;
		iter = iter->next;
	}
	return (sum / size);
}

int	get_range(t_stack **A)
{
	int		min_value;
	int		max_value;
	int		range;
	t_node	*max;
	t_node	*min;

	max = get_max(A);
	min = get_min(A);
	max_value = max->value;
	min_value = min->value;
	range = max_value - min_value;
	return (range);
}

int	detect_outliers(t_stack **A, int mean)
{
	t_node	*iter;
	int		count;

	count = 0;
	iter = (*A)->bot;
	while (iter)
	{
		if (iter->value <= mean)
			count++;
		iter = iter->next;
	}
	if (count >= 4)
		return (1);
	return (0);
}

t_node	*get_middle_node(t_stack **A)
{
	t_node	*iter;
	t_node	*max;
	t_node	*min;

	iter = (*A)->bot;
	max = get_max(A);
	min = get_min(A);
	while (iter)
	{
		if (iter->value != max->value && iter->value != min->value)
			return (iter);
		iter = iter->next;
	}
	return (iter);
}
