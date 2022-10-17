/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:53 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/17 18:33:28 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	copy_stack(int src[MAX_STACK], int dest[MAX_STACK], int stack_size)
{
	int	orig_size;

	orig_size = stack_size;
	while (orig_size--)
		dest[orig_size] = src[orig_size];
}

void	rank_stack(int stacks[3][MAX_STACK], int stack_sizes[3], int s_id)
{
	int	ranked[MAX_STACK];
	int	orig_size;
	int	smaller;

	orig_size = stack_sizes[s_id];
	while (orig_size--)
	{
		smaller = count_smaller_numbers(stacks[s_id], stack_sizes[s_id], stacks[s_id][orig_size]);
		ranked[orig_size] = smaller + 1;
	}
	copy_stack(ranked, stacks[s_id], stack_sizes[s_id]);
}

void	rev_stack(int stack[MAX_STACK], int stack_size)
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

int		check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return (-1);
	if (is_sort(stacks, stack_sizes, 0))
		return (1);
	return (0);
}
