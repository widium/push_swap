/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:53:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/20 10:15:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(char **argv, int argc)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (!(manage_args(argc, argv, &a, &b)))
	{
		ft_putstr_fd("Error\n", 1);
		return ;
	}
	if (is_sorted(&a))
		return ;
	choose_type_of_split(&a, &b);
	sort_a(&a, &b);
	push_max_b_to_a(&a, &b);
}
