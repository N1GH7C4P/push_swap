/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:30:01 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 18:01:30 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	push_smallest_nb(int stacks[3][MAX_STACK], int sizes[3], int id)
{
	int	i;
	int	nb;

	nb = get_smallest(stacks, sizes, id);
	i = get_index(stacks[id], sizes[id], nb);
	if (i != -1)
	{
		move_to_top(stacks, sizes, i, id);
		if (id == 1)
			select_cmd(stacks, sizes, "pa", 1);
		else
			select_cmd(stacks, sizes, "pb", 1);
		return (nb);
	}
	return (-1);
}

int	push_biggest_nb(int stacks[3][MAX_STACK], int sizes[3], int id)
{
	int	i;
	int	nb;

	nb = get_biggest(stacks, sizes, id);
	i = get_index(stacks[id], sizes[id], nb);
	if (i != -1)
	{
		move_to_top(stacks, sizes, i, id);
		if (id == 1)
			select_cmd(stacks, sizes, "pa", 1);
		else
			select_cmd(stacks, sizes, "pb", 1);
		return (nb);
	}
	return (-1);
}

void	push_all(int stacks[3][MAX_STACK], int sizes[3], int id)
{
	int	ret;

	ret = push_biggest_nb(stacks, sizes, id);
	stacks[2][ret] = 1;
	while (ret != -1)
	{
		ret = push_biggest_nb(stacks, sizes, id);
		stacks[2][ret] = 1;
	}
	clear_stack(stacks, sizes, id);
}
