/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:01:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/18 10:06:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*assign_stack_with_1_element(char **argv, int argc)
{
	t_node	*curr_node;
	t_stack	*stack;
	int		result;

	stack = create_stack();
	curr_node = create_node();
	result = ft_atoi(argv[0]);
	curr_node->value = result;
	stack->size = 1;
	stack->bot = curr_node;
	stack->top = curr_node;
	return (stack);
}

t_stack	*assign_stack_with_multiple_element(char **argv, int argc)
{
	t_node	*curr_node;
	t_node	*node_next;
	t_node	*tmp;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (i < 1)
		{
			curr_node = create_and_assign_node(argv, i);
			tmp = curr_node;
		}
		else
		{
			node_next = create_assign_connect_node(curr_node, argv, i);
			curr_node = node_next;
		}
		i++;
		size++;
	}
	return (create_and_assign_stack(tmp, node_next, size));
}

void	set_stack_null(t_stack **A)
{
	(*A)->bot = NULL;
	(*A)->top = NULL;
}