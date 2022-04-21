/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:23:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/21 11:26:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*organize_stack(char **argv, int argc, t_stack *A)
{
	int	i;
	int	size;
	int	result;

	i = 0;
	size = 0;
	if (argc == 1)
		return (assign_stack_with_1_element(argv, argc, A));
	return (assign_stack_with_multiple_element(argv, argc, A));
}

int	manage_args(int argc, char **argv, t_stack *A, t_stack *B)
{
	int		nbr_of_elements;
	char	**arguments;

	if (argc == 1)
		return (-1);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		nbr_of_elements = check_args(arguments, argc);
		if (!nbr_of_elements)
			return (0);
		else if (!nbr_of_elements)
			return (-1);
		A = organize_stack(arguments, nbr_of_elements, A);
	}
	else
	{
		if (!(check_args(argv + 1, argc)))
			return (0);
		else if (check_args(argv + 1, argc) == -1)
			return (-1);
		A = organize_stack(argv + 1, argc - 1, A);
	}
	return (1);
}

int	check_doublons(char **argv, int argc)
{
	if (argc > 1)
	{
		if (!(check_doublons_for_argc(argv, argc)))
			return (0);
	}
	else
	{
		if (!(check_doublons_for_argv(argv)))
			return (0);
		else
			return (check_nbr_argv(argv));
	}
	return (1);
}
