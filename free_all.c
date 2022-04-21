/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:25:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/21 13:38:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_nodes(t_stack *A)
{
	t_node	*top;

	while (A->top)
	{
		top = A->top;
		A->top = A->top->prev;
		free(top);
	}
	free(A);
	if (A)
		return (0);
	return (1);
}

int	free_all(t_stack *A, t_stack *B)
{
	if (!(free_nodes(A)))
		return (0);
	if (!(free_nodes(B)))
		return (0);
	return (1);
}


// void	free_elements(t_stack *a, t_stack *b)
// {
// 	t_node	*node;

// 	if (a->front != NULL)
// 	{
// 		while (a->front->next != NULL)
// 		{
// 			node = a->front;
// 			a->front = a->front->next;
// 			free(node);
// 		}
// 		free(a->front);
// 	}
// 	if (b->front != NULL)
// 	{
// 		while (b->front->next != NULL)
// 		{
// 			node = b->front;
// 			b->front = b->front->next;
// 			free(node);
// 		}
// 		free(b->front);
// 	}
// 	free(a);
// 	free(b);
// }
