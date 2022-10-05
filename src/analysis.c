/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:24 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 17:02:39 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
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
