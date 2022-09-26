/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:03:37 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/26 15:28:27 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

void run_command(int stacks[2][MAX_STACK], int stack_sizes[2], char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap_top(stacks[0], stack_sizes[0]);
	else if(!ft_strcmp(line, "sb"))
		swap_top(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(line, "ss"))
	{
		swap_top(stacks[0], stack_sizes[0]);
		swap_top(stacks[1], stack_sizes[1]);
	}
	else if (!ft_strcmp(line, "pa"))
		push_swap(stacks, stack_sizes, 1);
}

void push_swap(int stacks[2][MAX_STACK], int stack_sizes[2], int direction)
{
	// pa
	if (direction == 1)
	{
		if (stack_sizes[1] < 1)
			return ;
		stacks[0][stack_sizes[0]] = stacks[1][stack_sizes[1] - 1];
		stacks[1][stack_sizes[1] - 1] = 0;
		stack_sizes[0]++;
		stack_sizes[1]--;
	}
	// pb
	else if (direction == 2)
	{
		if (stack_sizes[0] < 1)
			return ;
		stacks[1][stack_sizes[1]] = stacks[0][stack_sizes[0] - 1];
		stacks[0][stack_sizes[0] - 1] = 0;
		stack_sizes[1]++;
		stack_sizes[0]--;
	}
}

void swap_top (int stack[MAX_STACK], int stack_size)
{
	if (stack_size < 2)
		return ;
	ft_swap(&stack[stack_size - 1], &stack[stack_size - 2]);
}