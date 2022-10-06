/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:24 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/06 14:43:08 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	is_sort(int stacks[3][MAX_STACK], int stack_sizes[3], int id)
{
	int	i;
	int	top_limiter;

	top_limiter = stack_sizes[id] - 2;
	i = 0;
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
	return (bits);
}
