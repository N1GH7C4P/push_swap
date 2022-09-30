/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:03:37 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/30 20:56:07 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

void run_command(int stacks[3][MAX_STACK], int stack_sizes[2], char *line, int verbose)
{
	if (verbose)
		ft_putendl(line);
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
	else if (!ft_strcmp(line, "pb"))
		push_swap(stacks, stack_sizes, 2);
	else if (!ft_strcmp(line, "ra"))
		rotate(stacks[0], stack_sizes[0]);
	else if (!ft_strcmp(line, "rb"))
		rotate(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(stacks[0], stack_sizes[0]);
		rotate(stacks[1], stack_sizes[1]);
	}
	else if (!ft_strcmp(line, "rra"))
		rev_rotate(stacks[0], stack_sizes[0]);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(line, "rrr"))
	{
		rev_rotate(stacks[0], stack_sizes[0]);
		rev_rotate(stacks[1], stack_sizes[1]);
	}
	else
		exit_program(1);
	//print_stacks(stacks, stack_sizes);
}

// pa & pb
// push <dest> - take the first element at the top of <src> and put it at the top of <dest>.
void push_swap(int stacks[3][MAX_STACK], int stack_sizes[2], int direction)
{
	if (direction == 1)
	{
		if (stack_sizes[1] < 1)
			return ;
		stacks[0][stack_sizes[0]] = stacks[1][stack_sizes[1] - 1];
		stacks[1][stack_sizes[1] - 1] = 0;
		stack_sizes[0]++;
		stack_sizes[1]--;
	}
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

// sa & sb & ss
// swap <stack> - swap the first 2 elements at the top of <stack>.
void swap_top (int stack[MAX_STACK], int stack_size)
{
	if (stack_size < 2)
		return ;
	ft_swap(&stack[stack_size - 1], &stack[stack_size - 2]);
}

// ra & rb & rr
// rotate <stack> - shift up all elements of <stack> a by 1. The first element becomes the last one.
void rotate(int stack[MAX_STACK], int stack_size)
{
	int	temp;
	int	i;

	if (stack_size < 2)
		return ;
	temp = stack[stack_size - 1];
	i = stack_size - 1;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = temp;
}

//rra & rrb & rrr
// reverse rotate <stack> - shift down all elements of <stack> a by 1. The last element becomes the first one.
void rev_rotate(int stack[MAX_STACK], int stack_size)
{
	int	temp;
	int	i;

	if (stack_size < 2)
		return ;
	temp = stack[0];
	i = 1;
	while (i < stack_size)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[stack_size - 1] = temp;
}

// Extra
void rev_stack(int stack[MAX_STACK], int stack_size)
{
	int	start;
	int	end;	
	int	temp;

	end = stack_size - 1;
	start = 0;
	while (start < end)
	{
		temp = stack[start];
		stack[start] = stack[end];
		stack[end] = temp;
		start++;
		end--;
	}
}
