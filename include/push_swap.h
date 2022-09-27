/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:29:45 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/27 16:13:49 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define MAX_ARGS 1000
# define MAX_STACK 2000
# include <unistd.h>
# include <stdio.h>

// Parser
int		parser(int argc, char **argv, int stacks[2][MAX_STACK], int	stack_sizes[2]);
int		parse_input_string(char *input, int stack[MAX_STACK]);
int		parse_arguments(char **argv, int stack[MAX_STACK], int stack_size);

//  Swap commands
void	run_command(int stacks[2][MAX_STACK], int stack_sizes[2], char *line);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	push_swap(int stacks[2][MAX_STACK], int stack_sizes[2], int direction);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	rotate(int stack[MAX_STACK], int stack_size);
void	rev_rotate(int stack[MAX_STACK], int stack_size);

#endif
