/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:50:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/20 17:01:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv, int argc)
{
	int	i;

	argc -= 1;
	i = 0;
	while (i < argc)
	{
		if (!(check_nbr_argv(argv)))
			return (-1);
		if (!(check_digit_in_str(argv, check_nbr_argv(argv))))
			return (0);
		if (!(check_doublons(argv, argc)))
			return (0);
		if (!(check_max_min_int(argv, argc)))
			return (0);
		i++;
	}
	if (argc == 1)
		return (check_nbr_argv(argv));
	return (1);
}

int	check_digit_in_str(char **argv, int len)
{
	int	i;
	int	y;
	int	lan;

	y = 0;
	while (y < len)
	{
		lan = ft_strlen(argv[y]);
		i = 0;
		while (i < lan)
		{
			if (!((argv[y][i] >= '0' && argv[y][i] <= '9')
			|| (argv[y][i] == '-')))
				return (0);
			i++;
		}
		y++;
	}
	return (1);
}

int	check_nbr_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	check_doublons_for_argc(char **argv, int argc)
{
	int	i;
	int	y;
	int	current_arg;
	int	next_arg;

	y = 0;
	while (y < argc)
	{
		current_arg = ft_atoi(argv[y]);
		i = y + 1;
		while (i < argc)
		{
			if (i != argc)
				next_arg = ft_atoi(argv[i]);
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

int	check_doublons_for_argv(char **argv)
{
	int	i;
	int	y;
	int	len;
	int	current_arg;
	int	next_arg;

	y = 0;
	len = check_nbr_argv(argv);
	while (y < len)
	{
		current_arg = ft_atoi(argv[y]);
		i = y + 1;
		while (i < len)
		{
			if (i != len)
				next_arg = ft_atoi(argv[i]);
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
