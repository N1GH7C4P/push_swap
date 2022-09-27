/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:07 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/27 18:09:49 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	static int	stacks[2][MAX_STACK];
	static int	stack_sizes[2];

	parser(argc, argv, stacks, stack_sizes);
	move_to_top(stacks, stack_sizes, 0, 0);
	print_stacks(stacks, stack_sizes);
}

void move_to_top(int stacks[2][MAX_STACK], int stack_sizes[2], int index, int stack_id)
{
	while (index != stack_sizes[stack_id] - 1)
	{
		if ((stack_sizes[stack_id] - index) > (stack_sizes[stack_id] / 2))
		{
			if (stack_id == 1)
				run_command(stacks, stack_sizes, "rrb", 1);
			else
				run_command(stacks, stack_sizes, "rra", 1);
			if (index == 0)
				index = stack_sizes[0] - 1;
			else
				index--;
		}
		else
		{
			if (stack_id == 1)
				run_command(stacks, stack_sizes, "rb", 1);
			else
				run_command(stacks, stack_sizes, "ra", 1);
			index++;
		}
		move_to_top(stacks, stack_sizes, index, stack_id);
	}
}

/*
void radix_sort(int	stacks[2][MAX_STACK], int stack_sizes[2])
{
	int bit;
	int i;

	bit = 0;
	while (bit < 16)
	{
		i = 0;
		while (i < stack_sizes[0])
		{
			if (stacks[0][i] & bit)
				
			i++;
		}
	}
}
*/