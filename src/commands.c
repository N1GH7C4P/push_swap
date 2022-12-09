/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:03:37 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:25 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// pa & pb
// push <dest> - take top of <src> and put it at the top of <dest>.
void	push_swap(int stacks[3][MAX_STACK], int stack_sizes[3], int dir)
{
	if (dir == 1)
	{
		if (stack_sizes[1] < 1)
			return ;
		stacks[0][stack_sizes[0]] = stacks[1][stack_sizes[1] - 1];
		stacks[1][stack_sizes[1] - 1] = 0;
		stack_sizes[0]++;
		stack_sizes[1]--;
	}
	else if (dir == 2)
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
void	swap_top(int stack[MAX_STACK], int stack_size)
{
	if (stack_size < 2)
		return ;
	ft_swap(&stack[stack_size - 1], &stack[stack_size - 2]);
}

// ra & rb & rr
// rotate <stack> - shift up <stack> a by 1. The first becomes the last.
void	rotate(int stack[MAX_STACK], int stack_size)
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
	stack[stack_size] = 0;
	stack[0] = temp;
}

//rra & rrb & rrr
// reverse rotate <stack> - shift down <stack> a by 1. The last the first.
void	rev_rotate(int stack[MAX_STACK], int stack_size)
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
