/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:01:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:59:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*assign_stack_with_1_element(char **argv, int argc, t_stack *A)
{
	t_node	*curr_node;
	int		result;

	curr_node = create_node();
	result = ft_atoi(argv[0]);
	curr_node->value = result;
	A->size = 1;
	A->bot = curr_node;
	A->top = curr_node;
	return (A);
}

t_stack	*assign_stack_multi_element(char **argv, int argc, t_stack *A)
{
	t_node	*curr_node;
	t_node	*node_next;
	t_node	*tmp;
	int		i;
	int		size;

	size = 0;
	i = argc - 1;
	while (i >= 0)
	{
		if (i == argc - 1)
		{
			curr_node = create_and_assign_node(argv, i);
			tmp = curr_node;
		}
		else
		{
			node_next = create_assign_connect_node(curr_node, argv, i);
			curr_node = node_next;
		}
		i--;
		size++;
	}
	return (assign_stack(tmp, node_next, size, A));
}

void	set_stack_null(t_stack *A)
{
	A->bot = NULL;
	A->top = NULL;
}
