/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:07 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/03 17:23:33 by kpolojar         ###   ########.fr       */
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
	print_stacks(stacks, stack_sizes);
}

int find_biggest_nb_index(int stack[MAX_STACK], int stack_size)
{
	int i;
	int biggest;
	int index;

	if (stack_size < 1)
		return (-1);
	i = 0;
	index = 0;
	biggest = INT_MIN;
	while (i < MAX_STACK)
	{
		if (stack[i] > biggest)
		{
			biggest = stack[i];
			index = i;
		}
		i++;
	}
	if (biggest > INT_MIN)
		return (index);
	else
		return (-1);
}

// direction (0) => A -> B, direction (1) => B -> A
int	push_biggest_nb_on_stack(int stacks[3][MAX_STACK], int stack_sizes[2], int direction)
{
	int index;

	index = find_biggest_nb_index(stacks[direction], stack_sizes[direction]);
	if (VERBOSE)
	{
		ft_putstr("biggest index: ");
		ft_putnbr(index);
		ft_putstr(" nb: ");
		ft_putnbr(stacks[direction][index]);
		ft_putstr(" stack_size: ");
		ft_putnbr(stack_sizes[direction]);
		ft_putendl("");
	}
	if (index != -1)
	{
		move_to_top(stacks[direction], stack_sizes[direction], index);
		if (!direction)
			run_command(stacks, stack_sizes, "pb", 1);
		else
			run_command(stacks, stack_sizes, "pa", 1);
		return (1);
	}
	return (0);
}

void move_to_top(int stack[MAX_STACK], int stack_size, int index)
{
	if (stack_size < 2)
		return ;
	if (index > stack_size)
	{
		ft_putendl("invalid index: ");
		ft_putnbr(index);
		ft_putstr(" > ");
		ft_putnbr(stack_size);
		ft_putendl("");
		exit(-1);
	}
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
			ft_putnbr(index);
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
	int bit;

	bit = 8;
	while (bit--)
	{
		if(VERBOSE)
			ft_putendl("Splitting stack B.");
		split_stack_by_bit(stacks, stack_sizes, bit);
		if (VERBOSE)
			print_stacks(stacks, stack_sizes);
		if(VERBOSE)
			ft_putendl("Returning all to A stack.");
		return_all_to_stack_a(stacks, stack_sizes);
		if (VERBOSE)
			print_stacks(stacks, stack_sizes);
	}
}

int test_bit(int nb, int bit)
{
	return (nb & (1 << bit));
}

int find_number_to_push(int stacks[3][MAX_STACK], int stack_sizes[2], int bit)
{
	int orig_stack_size;
	int nb;
	
	orig_stack_size = stack_sizes[0];
	while (orig_stack_size)
	{
		nb = stacks[0][orig_stack_size - 1];
		if (test_bit(nb, bit) && stacks[2][nb - 1] < 1)
		{
			if (VERBOSE)
				ft_putnbr(test_bit(stacks[0][orig_stack_size - 1], bit));
			stacks[2][nb - 1] = 1;
			return (orig_stack_size - 1);
		}
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
	int ret;

	ret = push_biggest_nb_on_stack(stacks, stack_sizes, 1);
	while (ret)
		ret = push_biggest_nb_on_stack(stacks, stack_sizes, 1);
}
