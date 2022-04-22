/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:57:06 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:22:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bot = NULL;
	return (ptr);
}

t_stack	*assign_stack(t_node *bot, t_node *top, int size, t_stack *A)
{
	A->size = size;
	A->bot = bot;
	A->top = top;
	return (A);
}

t_node	*create_and_assign_node(char **argv, int i)
{
	t_node	*curr_node;

	curr_node = create_node();
	curr_node->value = ft_atoi(argv[i]);
	return (curr_node);
}
