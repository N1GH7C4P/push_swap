/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:49:02 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/11 14:53:46 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	get_index(int s[3][MAX_STACK], int s_sizes[3], int stack_id, int nb)
{
	int	i;

	if (s_sizes[stack_id] < 1)
		return (-1);
	i = 0;
	while (i < MAX_STACK)
	{
		if (s[stack_id][i] == nb)
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
