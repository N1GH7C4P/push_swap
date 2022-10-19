/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:38:26 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 18:17:37 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DESCRIPTIVE_MESSAGES 0
# define MAX_ARGS 1000
# define MAX_STACK 2000
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define VERBOSE 0
# include <unistd.h>
# include <stdio.h>

// Analysis
int		find_number_to_push(int s[3][MAX_STACK], int sizes[3], int b, int g);
int		is_sort(int s[3][MAX_STACK], int s_sizes[3], int id);
int		is_sequenced(int stacks[3][MAX_STACK], int stack_sizes[3], int id);
int		count_bits(int n);
int		count_smaller_numbers(int s[MAX_STACK], int stack_size, int nb);

// Preparation
void	rev_stack(int s[MAX_STACK], int s_size);
void	copy_stack(int src[MAX_STACK], int dest[MAX_STACK], int s_size);
void	rank_stack(int stacks[3][MAX_STACK], int stack_sizes[3], int s_id);

// Checker
int		check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3]);

// Sorter
void	radix_sort(int stacks[3][MAX_STACK], int s_sizes[3]);
void	micro_sort(int stacks[3][MAX_STACK], int stack_sizes[3]);
void	mini_sort(int stacks[3][MAX_STACK], int stack_sizes[3]);

// Utils
void	copy_stack(int src[MAX_STACK], int dest[MAX_STACK], int s_size);
void	print_stacks(int s[3][MAX_STACK], int s_sizes[3]);
int		test_bit(int nb, int bit);
void	clear_stack(int s[2][MAX_STACK], int s_sizes[3], int s_id);
void	exit_program(int error, char *msg);

// Parser
int		parser(int argc, char **argv, int s[3][MAX_STACK], int stack_sizes[2]);
int		parse_input_string(char *input, int s[MAX_STACK]);
int		parse_arguments(char **argv, int s[MAX_STACK], int size, int skip);

// Command handling
void	select_cmd(int s[3][MAX_STACK], int s_sizes[3], char *line, int v);
void	run_cmd(int stacks[3][MAX_STACK], int stack_sizes[3], char *l);

//  Swap commands
void	swap_top(int s[MAX_STACK], int s_size);
void	push_swap(int s[3][MAX_STACK], int s_sizes[3], int direction);
void	swap_top(int s[MAX_STACK], int s_size);
void	swap_both(int s[3][MAX_STACK], int s_sizes[3]);
void	rotate(int s[MAX_STACK], int s_size);
void	rotate_both(int s[3][MAX_STACK], int s_sizes[3]);
void	rev_rotate(int s[MAX_STACK], int s_size);
void	rev_rotate_both(int s[3][MAX_STACK], int s_sizes[3]);

// Higher order commands
void	move_to_top(int s[3][MAX_STACK], int s_sizes[3], int index, int id);

// Complex commands
int		push_smallest_nb(int stacks[3][MAX_STACK], int sizes[3], int id);
int		push_biggest_nb(int s[3][MAX_STACK], int sizes[3], int id);
void	push_all(int s[3][MAX_STACK], int sizes[3], int id);

// Getters
int		get_index(int s[MAX_STACK], int s_size, int nb);
int		get_smallest(int s[3][MAX_STACK], int sizes[3], int id);
int		get_biggest(int s[3][MAX_STACK], int sizes[3], int id);
int		get_radix_median(int radix);
int		get_first_nonzero_index(int s[3][MAX_STACK], int id);
#endif