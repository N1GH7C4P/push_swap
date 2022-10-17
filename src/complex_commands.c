/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:30:01 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/17 15:17:41 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	go_high(int stacks[3][MAX_STACK], int sizes[3], int i, int id)
{
	int	biggest;
	int index;

	while (i != sizes[id] - 1)
	{
		if (id == 0)
		{
			biggest = get_biggest(stacks, sizes, 1);
			index = get_index(stacks, sizes, 1, biggest);
			if ((sizes[1] - index) <= (sizes[1] / 2))
				run_cmd(stacks, sizes, "rr", 1);
			else
				run_cmd(stacks, sizes, "ra", 1);
		}
		else
			run_cmd(stacks, sizes, "rb", 1);
		i++;
	}
}

static void	go_low(int stacks[3][MAX_STACK], int sizes[3], int i, int id)
{
	int	biggest;
	int index;

	while (i != sizes[id] - 1 && i >= 0)
	{
		if (id == 0)
		{
			biggest = get_biggest(stacks, sizes, 1);
			index = get_index(stacks, sizes, 1, biggest);
			if ((sizes[1] - index) > (sizes[1] / 2))
				run_cmd(stacks, sizes, "rrr", 1);
			else
				run_cmd(stacks, sizes, "rra", 1);
		}
		else
			run_cmd(stacks, sizes, "rrb", 1);
		if (i == 0)
			i = sizes[id] - 1;
		else
			i--;
	}
}

void	move_to_top(int stacks[3][MAX_STACK], int sizes[3], int i, int id)
{
	if (sizes[id] < 2)
		return ;
	if (i > sizes[id])
		exit(-1);
	if ((sizes[id] - i) > (sizes[id] / 2))
		go_low(stacks, sizes, i, id);
	else
		go_high(stacks, sizes, i, id);
}

int	push_biggest_nb(int stacks[3][MAX_STACK], int sizes[3], int id)
{
	int	i;
	int	nb;

	nb = get_biggest(stacks, sizes, id);
	i = get_index(stacks, sizes, id, nb);
	if (i != -1)
	{
		move_to_top(stacks, sizes, i, id);
		if (id == 1)
			run_cmd(stacks, sizes, "pa", 1);
		else
			run_cmd(stacks, sizes, "pb", 1);
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
