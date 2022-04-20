/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/20 18:44:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_shortest_candidate(t_stack **A, int group)
{
	int		candidate_top;
	int		candidate_bot;
	t_node	*top;
	t_node	*bot;
	t_node	*node_candidate_top;
	t_node	*node_candidate_bot;

	top = (*A)->top;
	bot = (*A)->bot;
	candidate_top = get_candidate_top(A, top, group);
	candidate_bot = get_candidate_bot(A, bot, group);
	printf("candidate_top -> (%d)\n", candidate_top);
	printf("candidate_bot -> (%d)\n", candidate_bot);
	node_candidate_top = get_node_index_top(A, candidate_top);
	node_candidate_bot = get_node_index_bot(A, candidate_bot - 1);
	printf("candidate_top -> (%d)\n", node_candidate_top->value);
	printf("candidate_bot -> (%d)\n", node_candidate_bot->value);
	if (candidate_top <= candidate_bot)
		return (get_index(A, node_candidate_top->value));
	return (get_index(A, node_candidate_bot->value));
}

int	get_candidate_top(t_stack **A, t_node *top_iter, int group)
{
	int	candidate_top;

	while (top_iter)
	{
		if (top_iter->value < group)
		{
			candidate_top = get_index_top(A, top_iter->value);
			return (candidate_top);
		}
		top_iter = top_iter->prev;
	}
	return (get_index_top(A, top_iter->next->value));
}

int	get_candidate_bot(t_stack **A, t_node *bot, int group)
{
	int	candidate_bot;

	while (bot)
	{
		if (bot->value < group)
		{
			candidate_bot = get_index(A, bot->value) + 1;
			return (candidate_bot);
		}
		bot = bot->next;
	}
	return (get_index(A, bot->prev->value));
}

t_node	*get_node_index_top(t_stack **A, int index_top)
{
	int		i;
	t_node	*iter;

	i = 0;
	iter = (*A)->top;
	while (iter)
	{
		if (i == index_top)
			return (iter);
		i++;
		iter = iter->prev;
	}
	return (iter->next);
}

t_node	*get_node_index_bot(t_stack **A, int index_bot)
{
	int		i;
	t_node	*iter;

	i = 0;
	iter = (*A)->bot;
	while (iter)
	{
		if (i == index_bot)
			return (iter);
		i++;
		iter = iter->next;
	}
	return (iter->next);
}
