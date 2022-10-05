/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:02 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 17:04:18 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

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
