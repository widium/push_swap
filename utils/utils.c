/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:50:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 16:03:28 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack **A)
{
	int		size;
	int		i;
	t_node	*iter;

	iter = (*A)->bot;
	size = (*A)->size;
	i = 0;
	while (i < (size - 1))
	{
		if (iter->value < iter->next->value)
			return (0);
		i++;
		iter = iter->next;
	}
	return (1);
}

int	inverse_sorted(t_stack **A)
{
	int		size;
	int		i;
	t_node	*iter;

	iter = (*A)->bot;
	size = (*A)->size;
	i = 0;
	while (iter)
	{
		if (iter->prev)
		{
			if (iter->value < iter->prev->value)
				return (0);
			iter = iter->prev;
		}
		else
			break ;
	}
	return (1);
}

int	swap_min_max(t_stack **A, t_node *top_prev, t_node *top)
{
	int	top_value;
	int	top_prev_value;

	top_value = top->value;
	top_prev_value = top_prev->value;
	if (is_min(A, top_value) && is_max(A, top_prev_value))
		return (1);
	return (0);
}

int	check_max_min_int(char **argv, int argc)
{
	int				i;
	long long int	current_arg;

	i = 0;
	while (i < argc)
	{
		current_arg = ft_atol(argv[i]);
		if (current_arg > INT_MAX || current_arg < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
