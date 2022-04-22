/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_function_2_in_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:49:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:17:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack **A, t_stack **B)
{
	if (!(*A)->top)
		return ;
	swap_a(A);
	if (!(*B)->top)
		return ;
	swap_b(B);
	ft_putstr_fd("ss\n", 1);
}

void	rotate(t_stack **A, t_stack **B)
{
	if (!(*A)->top)
		return ;
	rotate_a(A);
	if (!(*B)->top)
		return ;
	rotate_b(B);
	ft_putstr_fd("rr\n", 1);
}

void	reverse(t_stack **A, t_stack **B)
{
	if (!(*A)->top)
		return ;
	reverse_rotate_a(A);
	if (!(*B)->top)
		return ;
	reverse_rotate_b(B);
	ft_putstr_fd("rrr\n", 1);
}
