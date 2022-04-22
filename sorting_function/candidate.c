/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:20:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_of_shortest_candidate(t_stack **A, int group)
{
	int		index_candidate_top;
	int		index_candidate_bot;
	t_node	*node_candidate_top;
	t_node	*node_candidate_bot;

	index_candidate_top = get_candidate_top(A, (*A)->top, group);
	index_candidate_bot = get_candidate_bot(A, (*A)->bot, group);
	node_candidate_top = get_node_index_top(A, index_candidate_top);
	node_candidate_bot = get_node_index_bot(A, index_candidate_bot - 1);
	if (index_candidate_top <= index_candidate_bot)
		return (get_index(A, node_candidate_top->value));
	return (get_index(A, node_candidate_bot->value));
}

int	get_candidate_top(t_stack **A, t_node *top_iter, int group)
{
	int		candidate_top;
	t_node	*next;

	while (top_iter)
	{
		if (top_iter->value < group)
		{
			candidate_top = get_index_top(A, top_iter->value);
			return (candidate_top);
		}
		next = top_iter;
		top_iter = top_iter->prev;
	}
	return (get_index(A, next->value));
}

int	get_candidate_bot(t_stack **A, t_node *bot_iter, int group)
{
	int		candidate_bot;
	t_node	*prev;

	while (bot_iter)
	{
		if (bot_iter->value < group)
		{
			candidate_bot = get_index(A, bot_iter->value) + 1;
			return (candidate_bot);
		}
		prev = bot_iter;
		bot_iter = bot_iter->next;
	}
	return (get_index(A, prev->value));
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
	return (iter->prev);
}
