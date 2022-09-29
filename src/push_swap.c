/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:07 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/29 16:56:34 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	static int	stacks[2][MAX_STACK];
	static int	stack_sizes[2];

	parser(argc, argv, stacks, stack_sizes);
	rank_stack(stacks[0], stack_sizes[0]);
	radix_sort(stacks, stack_sizes);
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

int count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb)
{
	int orig_size;
	int smaller;

	orig_size = stack_size;
	smaller = 0;
	while (orig_size--)
	{
		if (stack[orig_size] < nb)
			smaller++;
	}
	return (smaller);
}

void copy_stack(int	src[MAX_STACK], int	dest[MAX_STACK], int stack_size)
{
	int orig_size = stack_size;
	while (orig_size--)
		dest[orig_size] = src[orig_size];
}

void rank_stack(int	stack[MAX_STACK], int stack_size)
{
	int	ranked[MAX_STACK];
	int orig_stack_size;
	int smaller;

	orig_stack_size = stack_size;
	while (orig_stack_size--)
	{
		smaller = count_smaller_numbers(stack, stack_size, stack[orig_stack_size]);
		ranked[orig_stack_size] = smaller; 
	}
	copy_stack(ranked, stack, stack_size);
}

void radix_sort(int	stacks[2][MAX_STACK], int stack_sizes[2])
{
	int nb_of_bits;
	int bit;

	nb_of_bits = 32;
	bit = 1;
	while (bit <= nb_of_bits)
	{
		split_stack_by_bit(stacks, stack_sizes, bit);
		return_all_to_stack_a(stacks, stack_sizes);
		bit++;
	}
}

void split_stack_by_bit(int	stacks[2][MAX_STACK], int stack_sizes[2], int bit)
{
	int orig_stack_size;

	orig_stack_size = stack_sizes[0];
	while (orig_stack_size)
	{
		if (stacks[0][stack_sizes[0] - 1] & bit)
			run_command(stacks, stack_sizes, "pb", 1);
		else
			run_command(stacks, stack_sizes, "ra", 1);
		orig_stack_size--;
	}
}

void	return_all_to_stack_a(int stacks[2][MAX_STACK], int stack_sizes[2])
{
	while (stack_sizes[1] > 0)
		run_command(stacks, stack_sizes, "pa", 1);
}
