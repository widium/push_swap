/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:03:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/18 10:07:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect_node(t_node *curr_node, t_node *node_next)
{
	curr_node->next = node_next;
	node_next->prev = curr_node;
}

t_node	*create_assign_connect_node(t_node *curr_node, char **argv, int i)
{
	t_node	*node_next;

	node_next = create_node();
	node_next->value = ft_atoi(argv[i]);
	connect_node(curr_node, node_next);
	return (node_next);
}
