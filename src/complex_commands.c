/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:30:01 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/11 14:51:53 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	go_high(int stacks[3][MAX_STACK], int stack_sizes[3], int i, int id)
{
	while (i != stack_sizes[id] - 1)
	{
		if (id == 0)
			run_cmd(stacks, stack_sizes, "ra", 1);
		else
			run_cmd(stacks, stack_sizes, "rb", 1);
		i++;
	}
}

static void	go_low(int stacks[3][MAX_STACK], int stack_sizes[3], int i, int id)
{
	while (i != stack_sizes[id] - 1 && i >= 0)
	{
		if (id == 0)
			run_cmd(stacks, stack_sizes, "rra", 1);
		else
			run_cmd(stacks, stack_sizes, "rrb", 1);
		if (i == 0)
			i = stack_sizes[id] - 1;
		else
			i--;
	}
}

void	move_to_top(int stacks[3][MAX_STACK], int stack_sizes[3], int i, int id)
{
	if (stack_sizes[id] < 2)
		return ;
	if (i > stack_sizes[id])
		exit(-1);
	if ((stack_sizes[id] - i) > (stack_sizes[id] / 2))
		go_low(stacks, stack_sizes, i, id);
	else
		go_high(stacks, stack_sizes, i, id);
}

int	push_biggest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int id)
{
	int	i;
	int	nb;

	i = get_index(stacks, stack_sizes, id, get_biggest(stacks, stack_sizes, id));
	if (i != -1)
	{
		move_to_top(stacks, stack_sizes, i, id);
		nb = stacks[id][stack_sizes[id] - 1];
		if (id == 1)
			run_cmd(stacks, stack_sizes, "pa", 1);
		else
			run_cmd(stacks, stack_sizes, "pb", 1);
		return (nb);
	}
	return (-1);
}

void	push_all(int stacks[3][MAX_STACK], int stack_sizes[3], int id)
{
	int	ret;

	ret = push_biggest_nb(stacks, stack_sizes, id);
	stacks[2][ret] = 1;
	while (ret != -1)
	{
		ret = push_biggest_nb(stacks, stack_sizes, id);
		stacks[2][ret] = 1;
	}
	clear_stack(stacks, stack_sizes, id);
}
