/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:53:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:27:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(char **argv, int argc)
{
	int		result;
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	result = manage_args(argc, argv, a, b);
	if (result == 0)
	{
		ft_putstr_fd("Error\n", 1);
		return ;
	}
	if (result == -1)
		return ;
	if (is_sorted(&a))
		return ;
	if (a->size < 4)
	{
		sort_fast(&a, &b);
		return ;
	}
	choose_type_of_split(&a, &b);
	sort_a(&a, &b);
	push_max_b_to_a(&a, &b);
	free_all(a, b);
}
