/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:07 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/30 20:53:56 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	stack_sizes[2];

	parser(argc, argv, stacks, stack_sizes);
	rank_stack(stacks[0], stack_sizes[0]);
	radix_sort(stacks, stack_sizes);
}

void move_to_top(int stack[MAX_STACK], int stack_size, int index)
{
	if ((stack_size - index) > (stack_size / 2))
	{
		while (index != stack_size - 1)
		{
			rev_rotate(stack, stack_size);
			ft_putendl("rra");
			if (index == 0)
				index = stack_size - 1;
			else
				index--;
		}
	}
	else
	{
		while (index != stack_size - 1)
		{
			rotate(stack, stack_size);
			ft_putendl("ra");
			index++;
		}
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
		ranked[orig_stack_size] = smaller + 1; 
	}
	copy_stack(ranked, stack, stack_size);
}

void radix_sort(int	stacks[3][MAX_STACK], int stack_sizes[2])
{
	int nb_of_bits;
	int bit;

	nb_of_bits = 8;
	bit = 1;
	while (bit <= nb_of_bits)
	{
		split_stack_by_bit(stacks, stack_sizes, bit);
		return_all_to_stack_a(stacks, stack_sizes);
		bit++;
	}
}

int test_bit(int nb, int bit)
{
	return (nb & bit);
}

int find_number_to_push(int stacks[3][MAX_STACK], int stack_sizes[2], int bit)
{
	int orig_stack_size;

	orig_stack_size = stack_sizes[0];
	while (orig_stack_size)
	{
		if (test_bit(stacks[0][orig_stack_size - 1], bit))
			return (orig_stack_size - 1);
		orig_stack_size--;
	}
	return (-1);
}

void split_stack_by_bit(int	stacks[3][MAX_STACK], int stack_sizes[2], int bit)
{
	int index;

	index = find_number_to_push(stacks, stack_sizes, bit);
	while (index != -1)
	{
		move_to_top(stacks[0], stack_sizes[0], index);
		run_command(stacks, stack_sizes, "pb", 1);
		index = find_number_to_push(stacks, stack_sizes, bit);
	}
}

void	return_all_to_stack_a(int stacks[3][MAX_STACK], int stack_sizes[2])
{
	while (stack_sizes[1] > 0)
		run_command(stacks, stack_sizes, "pa", 1);
}
