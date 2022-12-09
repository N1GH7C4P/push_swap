/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:53 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:47 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_stack(int src[MAX_STACK], int dest[MAX_STACK], int stack_size)
{
	int	orig_size;

	orig_size = stack_size;
	while (orig_size--)
		dest[orig_size] = src[orig_size];
}

void	rank_stack(int s[3][MAX_STACK], int sizes[3], int id)
{
	int	ranked[MAX_STACK];
	int	orig_size;
	int	c;

	orig_size = sizes[id];
	while (orig_size--)
	{
		c = count_smaller_numbers(s[id], sizes[id], s[id][orig_size]);
		ranked[orig_size] = c + 1;
	}
	copy_stack(ranked, s[id], sizes[id]);
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
