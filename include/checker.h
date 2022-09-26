/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:28:41 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/26 15:28:11 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define MAX_ARGS 1000
# define MAX_STACK 2000
# include <unistd.h>
# include <stdio.h>
//# include <stdlib.h>

// Utils
int		find_smallest_nb_index(int stack[MAX_STACK], size_t stack_sizes[2]);
void	print_stack(int stack[MAX_STACK], size_t stack_size);

//  Swap commands
void	run_command(int stacks[2][MAX_STACK], int stack_sizes[2], char *line);
void	swap_top (int stack[MAX_STACK], int stack_size);

#endif
