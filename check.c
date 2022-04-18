/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:50:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/15 16:02:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(check_str(argv[i], ft_strlen(argv[i]))))
		{
			ft_putstr_fd("--- Error ---\n", 1);
			return (0);
		}
		if (!(check_doublons(argv, argc)))
		{
			ft_putstr_fd("--- Error ---\n", 1);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		return (check_nbr_argv(argv));
	return (1);
}

int	check_str(char *argv, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_nbr_argv(char **argv)
{
	int	i;

	if (!argv)
		return (-1);
	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	check_doublons(char **argv, int argc)
{
	int	i;
	int	y;
	int	current_arg;
	int	next_arg;

	while (y < argc)
	{
		current_arg = ft_atoi(argv[y]);
		i = 2;
		while (i < argc)
		{
			if (!(y == argc - 1))
				next_arg = ft_atoi(argv[y + 1]);
			else
				return (1);
			if (current_arg == next_arg)
				return (0);
			i++;
		}
		y++;
	}
	return (1);
}
