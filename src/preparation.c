/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:53 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 16:29:31 by kpolojar         ###   ########.fr       */
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

void	rank_stack(int stack[MAX_STACK], int stack_size)
{
	int	ranked[MAX_STACK];
	int	orig_size;
	int	smaller;

	orig_size = stack_size;
	while (orig_size--)
	{
		smaller = count_smaller_numbers(stack, stack_size, stack[orig_size]);
		ranked[orig_size] = smaller + 1;
	}
	copy_stack(ranked, stack, stack_size);
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
