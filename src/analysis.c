/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:24 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/17 16:16:31 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int is_sequenced(int stacks[3][MAX_STACK], int stack_sizes[3], int id)
{
	int	index;
	int	i;

	if (stack_sizes[1] > 0)
		return (0);
	index = get_index(stacks, stack_sizes, id, get_biggest(stacks, stack_sizes, id));
	i = 0;
	while (i < stack_sizes[id] - 2)
	{
		if (index == stack_sizes[id] - 1)
		{
			if (stacks[id][index] != (stacks[id][0] + 1) && stacks[id][index] != (stacks[id][0]))
				return (0);
			index = 0;
		}
		if (stacks[id][index] != (stacks[id][index + 1] + 1) && stacks[id][index] != (stacks[id][index + 1]))
			return (0);
		index++;
		i++;
	}
	return (1);
}

int	is_sort(int stacks[3][MAX_STACK], int stack_sizes[3], int id)
{
	int	i;
	int	top_limiter;

	top_limiter = stack_sizes[id] - 1;
	i = 0;
	if (stack_sizes[1] > 0)
		return (0);
	while (i < top_limiter)
	{
		if (stacks[id][i] != (stacks[id][i + 1] + 1))
			return (0);
		i++;
	}
	return (1);
}

int	check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return (-1);
	if (is_sort(stacks, stack_sizes, 0))
		return (1);
	return (0);
}

int	count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb)
{
	int	orig_size;
	int	smaller;

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
	int	bits;

	if (n == 0)
		return (0);
	bits = 0;
	while (n != 0)
	{
		n = n / 2;
		bits++;
	}
	bits--;
	return (bits);
}

int	get_radix_median(int radix)
{
	int	median;

	median = 1;
	while (radix)
	{
		median = median * 2;
		radix--;
	}
	return (median + median / 2);
}
