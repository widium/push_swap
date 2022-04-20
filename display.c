/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:55:12 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/20 10:59:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_stack **A, t_stack **B)
{
	char	*stack_a;
	char	*stack_b;
	t_node	*node_a;
	t_node	*node_b;

	node_a = (*A)->top;
	node_b = (*B)->top;
	stack_a = "---A---";
	stack_b = "---B---";
	printf("%7s ||| %7s\n", stack_a, stack_b);
	while (node_a != NULL && node_b != NULL)
	{
		printf("%7i ||| %7i\n", node_a->value, node_b->value);
		node_a = node_a->prev;
		node_b = node_b->prev;
	}
	while (node_a)
	{
		printf("%7i ||| XXXXXXX\n", node_a->value);
		node_a = node_a->prev;
	}
	while (node_b)
	{
		printf("XXXXXXX ||| %7i\n", node_b->value);
		node_b = node_b->prev;
	}
}

void	print_stack(t_node *tmp)
{
	printf("--- Stack ---\n");
	while (tmp != NULL)
	{
		printf("    | %d |\n", tmp->value);
		tmp = tmp->next;
	}
	printf("-------------\n");
}
