/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:29:45 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/03 17:25:50 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define MAX_ARGS 1000
# define MAX_STACK 2000
# define VERBOSE 1
# include <unistd.h>
# include <stdio.h>

// Sorter
void	split_stack_by_bit(int	stacks[3][MAX_STACK], int stack_sizes[2], int bit);
void	return_all_to_stack_a(int stacks[3][MAX_STACK], int stack_sizes[2]);
void	radix_sort(int	stacks[3][MAX_STACK], int stack_sizes[2]);

// Utils
void	copy_stack(int	src[MAX_STACK], int	dest[MAX_STACK], int stack_size);
void	print_stacks(int stacks[3][MAX_STACK], int stack_sizes[2]);
void	rank_stack(int	stack[MAX_STACK], int stack_size);
int		count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb);

// Parser
int		parser(int argc, char **argv, int stacks[3][MAX_STACK], int	stack_sizes[2]);
int		parse_input_string(char *input, int stack[MAX_STACK]);
int		parse_arguments(char **argv, int stack[MAX_STACK], int stack_size);

//  Swap commands
void	run_command(int stacks[3][MAX_STACK], int stack_sizes[2], char *line, int verbose);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	push_swap(int stacks[3][MAX_STACK], int stack_sizes[2], int direction);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	rotate(int stack[MAX_STACK], int stack_size);
void	rev_rotate(int stack[MAX_STACK], int stack_size);

// Higher order commands
void	move_to_top(int stacks[3][MAX_STACK], int stack_sizes[2], int index, int stack_id);

#endif
