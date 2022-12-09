/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:02 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:31 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index(int s[MAX_STACK], int s_size, int nb)
{
	int	i;

	if (s_size < 1)
		return (-1);
	i = 0;
	while (i < MAX_STACK)
	{
		if (s[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	get_smallest(int s[3][MAX_STACK], int s_sizes[3], int stack_id)
{
	int		i;
	long	smallest;
	long	limit;

	limit = 2147483648l;
	if (s_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	smallest = limit;
	while (i < MAX_STACK)
	{
		if (s[stack_id][i] < smallest && s[stack_id][i] > 0)
			smallest = s[stack_id][i];
		i++;
	}
	if (smallest < limit)
		return (smallest);
	else
		return (-1);
}

int	get_biggest(int s[3][MAX_STACK], int s_sizes[3], int stack_id)
{
	int		i;
	long	biggest;
	long	limit;

	limit = -2147483649l;
	if (s_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	biggest = limit;
	while (i < MAX_STACK)
	{
		if (s[stack_id][i] > biggest)
			biggest = s[stack_id][i];
		i++;
	}
	if (biggest > limit)
		return (biggest);
	else
		return (-1);
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

int	get_first_nonzero_index(int s[3][MAX_STACK], int id)
{
	int	i;

	i = 0;
	while (i < MAX_STACK)
	{
		if (s[id][i] != 0)
			return (i);
		i++;
	}
	return (-1);
}
