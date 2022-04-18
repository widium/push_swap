/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:48:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/18 12:08:00 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int	get_mediane_average(t_stack **A)
// {
// 	int		mediane_value;
// 	int		before_mediane_value;
// 	int		average_mediane;
// 	int		me;
// 	int		size;
// 	int		i;
// 	t_node	*iter;

// 	iter = (*A)->bot;
// 	size = (*A)->size;

// 	//printf("Size -> (%d)\n", size);
// 	if (size < 2)
// 		return ((*A)->top->value);

// 	me = size / 2;	
// 	i = 0;
// 	while (i < (me + 1))
// 	{
// 		if (i >= 1)
// 			before_mediane_value = iter->prev->value;
// 		mediane_value = iter->value;
// 		i++;
// 		iter = iter->next;
// 	}
// 	if (size % 2 == 0)
// 	{
// 		average_mediane = (before_mediane_value + mediane_value) / 2;
// 		return (average_mediane);
// 	}
// 	else
// 		return (mediane_value);
// }
