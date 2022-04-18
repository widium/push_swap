/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:23:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/15 16:02:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*organize_stack(char **argv, int argc)
{
	int	i;
	int	size;
	int	result;

	i = 0;
	size = 0;
	if (argc == 1)
		return (assign_stack_with_1_element(argv, argc));
	return (assign_stack_with_multiple_element(argv, argc));
}

int	manage_args(int argc, char **argv, t_stack **A, t_stack **B)
{
	int		nbr_of_elements;
	char	**arguments;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		nbr_of_elements = check_args(arguments, argc);
		*A = organize_stack(arguments, nbr_of_elements);
	}
	else
	{
		if (!(check_args(argv, argc)))
			return (0);
		*A = organize_stack(argv + 1, argc);
	}
	return (1);
}
