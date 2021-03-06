/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:47:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/04/22 09:59:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

t_node			*create_node(void);
t_stack			*create_stack(void);

void			print_stack(t_stack **A);
void			display(t_stack **A, t_stack **B);

void			connect_node(t_node *curr_node, t_node *next_node);
t_stack			*organize_stack(char **argv, int argc, t_stack *A);
int				manage_args(int argc, char **argv, t_stack *a, t_stack *b);
int				check_empty_argv(char **argv, int len);
int				check_doublons(char **argv, int argc);
int				check_doublons_for_argc(char **argv, int argc);
int				check_doublons_for_argv(char **argv);
int				check_nbr_argv(char **argv);
int				check_args(char **argv, int argc);
int				check_digit_in_str(char **argv, int len);
int				check_max_min_int(char **argv, int argc);
long long int	ft_atol(const char *str);

void			set_stack_null(t_stack *A);
t_stack			*assign_stack_with_1_element(char **argv, int argc, t_stack *A);
t_stack			*assign_stack_multi_element(char **argv, int argc, t_stack *A);
t_node			*create_and_assign_node(char **argv, int i);
t_stack			*assign_stack(t_node *bot, t_node *top, int size, t_stack *A);
t_node			*create_assign_connect_node(t_node *node, char **argv, int i);

int				create_groups_for_split(t_stack **A);
int				create_size_group(t_stack **A);

void			swap_a(t_stack **A);
void			swap_b(t_stack **B);
void			ss(t_stack **A, t_stack **B);

void			push_b(t_stack **A, t_stack **B);
void			push_a(t_stack **A, t_stack **B);

void			rotate_a(t_stack **A);
void			rotate_b(t_stack **B);
void			rotate(t_stack **A, t_stack **B);

void			reverse_rotate_a(t_stack **A);
void			reverse_rotate_b(t_stack **B);
void			reverse(t_stack **A, t_stack **B);

void			choose_rotate_max(t_stack **A);
void			choose_rotate_min(t_stack **A);
void			choose_rotate_group(t_stack **A, int group);
void			choose_faster(t_stack **A, int min, int mid, int max);
int				swap_min_max(t_stack **A, t_node *top_prev, t_node *top);

int				get_range(t_stack **A);
int				get_mean(t_stack **A);
int				larger_than_groups(t_stack **A, int group);
int				smaller_than_groups(t_stack **A, int group);
int				index_of_shortest_candidate(t_stack **A, int group);
int				get_candidate_top(t_stack **A, t_node *top, int group);
int				get_candidate_bot(t_stack **A, t_node *bot, int group);
t_node			*get_node_index_top(t_stack **A, int index_top);
t_node			*get_node_index_bot(t_stack **A, int index_bot);

int				is_min(t_stack **B, int value);
int				is_max(t_stack **A, int value);
int				get_sqrt(int nbr);
int				detect_outliers(t_stack **A, int mean);
void			split_stack_group(t_stack **A, t_stack **B);
void			split_stack_mean(t_stack **A, t_stack **B);
void			choose_type_of_split(t_stack **A, t_stack **B);

int				get_index(t_stack **A, int value);
int				get_index_top(t_stack **A, int value);
t_node			*get_middle(t_stack **A);

t_node			*get_max(t_stack **A);
t_node			*get_min(t_stack **A);
t_node			*get_middle_node(t_stack **A);

int				is_sorted(t_stack **A);
int				inverse_sorted(t_stack **A);

void			sort_a(t_stack **A, t_stack **B);
void			sort_fast(t_stack **A, t_stack **B);
void			sort(char **argv, int argc);
void			push_max_b_to_a(t_stack **A, t_stack **B);
void			push_group_to_b(t_stack **A, t_stack **B, int grp, int siz_grp);
void			print_str_str(char **argv);

int				free_nodes(t_stack *A);
int				free_stack(t_stack *A);
int				free_all(t_stack *A, t_stack *B);
#endif