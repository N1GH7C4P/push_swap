/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/04 15:58:32 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3], int verbose)
{
	int	i;
	int	prev;

	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
	{
		if (verbose)
			ft_putendl("Invalid stack sizes");
		return -1;
	}
	prev = INT_MAX;
	i =  0;
	while (i < stack_sizes[0])
	{
		if (stacks[0][i] > prev)
		{
			if (verbose)
			{
				ft_putnbr(stacks[0][i]);
				ft_putstr(" > ");
				ft_putnbr(prev);
				ft_putendl("");
			}
			return (-1);
		}
		else
			prev = stacks[0][i];
		i++;
	}
	return (1);
}

void print_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	size_t	i;
	size_t	bigger_stack_size;

	if (stack_sizes[0] > stack_sizes[1])
		bigger_stack_size = stack_sizes[0];
	else
		bigger_stack_size = stack_sizes[1];
	i = 0;
	ft_putendl("-----");
	while (i < bigger_stack_size)
	{	
		ft_putstr("i: ");
		ft_putnbr(i);
		ft_putstr(" | ");
		ft_putnbr(stacks[0][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[1][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[2][i]);
		ft_putendl("");
		i++;
	}
	ft_putendl("-----");
	ft_putnbr(stack_sizes[0]);
	ft_putstr(" | ");
	ft_putnbr(stack_sizes[1]);
	ft_putendl("");
	return ;
}

 void exit_program(int error)
{
	if (error)
	{
		ft_putendl("Error");
		exit(-1);
	}
	exit(0);
}

int find_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id, int nb)
{
	int i;

	if (stack_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	while (i < MAX_STACK)
	{
		if (stacks[stack_id][i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int find_smallest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;
	int smallest;
	int	index;

	if (stack_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	smallest = INT_MAX;
	while (i < MAX_STACK)
	{
		if (stacks[stack_id][i] < smallest)
		{
			smallest = stacks[stack_id][i];
			index = i;
		}
		i++;
	}
	if (smallest > INT_MAX)
		return (index);
	else
		return (-1);
}

int find_smallest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;
	int smallest;

	if (VERBOSE)
	{
		ft_putstr("stack size: ");
		ft_putnbr(stack_sizes[stack_id]);
		ft_putendl("");
	}
	
	if (stack_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	smallest = INT_MAX;
	while (i < MAX_STACK)
	{
		if (stacks[stack_id][i] < smallest && stacks[stack_id][i] > 0)
			smallest = stacks[stack_id][i];
		i++;
	}
	if (smallest < INT_MAX)
		return (smallest);
	else
		return (-1);
}

int find_biggest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;
	int biggest;

	if (stack_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	biggest = INT_MIN;
	while (i < MAX_STACK)
	{
		if (stacks[stack_id][i] > biggest)
			biggest = stacks[stack_id][i];
		i++;
	}
	if (biggest > INT_MIN)
		return (biggest);
	else
		return (-1);
}

int find_biggest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;
	int biggest;
	int index;

	if (stack_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	index = 0;
	biggest = INT_MIN;
	while (i < MAX_STACK)
	{
		if (stacks[stack_id][i] > biggest)
		{
			biggest = stacks[stack_id][i];
			index = i;
		}
		i++;
	}
	if (biggest > INT_MIN)
		return (index);
	else
		return (-1);
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

int	count_bits(int n)
{
	int bits;

	if (n == 0)
		return 0;
	bits = 0;
	while (n != 0) {
		n = n / 2;
		bits++;
	}
	return (bits);
}

int	test_bit(int nb, int bit)
{
	return (nb & (1 << bit));
}

void	clear_stack(int stacks[2][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;

	i = 0;
	while (i < MAX_STACK)
	{
		stacks[stack_id][i] = 0;
		i++;
	}
	stack_sizes[stack_id] = 0;
}
