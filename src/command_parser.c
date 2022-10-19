/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:53:39 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 18:01:13 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	select_cmd(int s[3][MAX_STACK], int sizes[3], char *l, int v)
{
	if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") || !ft_strcmp(l, "ss")
		|| !ft_strcmp(l, "pa") || !ft_strcmp(l, "pb") || !ft_strcmp(l, "ra")
		|| !ft_strcmp(l, "rb") || !ft_strcmp(l, "rr") || !ft_strcmp(l, "rra")
		|| !ft_strcmp(l, "rrb") || !ft_strcmp(l, "rrr"))
	{
		if (v)
			ft_putendl(l);
		run_cmd(s, sizes, l);
		return ;
	}
	else
		exit_program(-1, "Error");
}

void	run_cmd(int stacks[3][MAX_STACK], int stack_sizes[3], char *l)
{
	if (!ft_strcmp(l, "sa"))
		swap_top(stacks[0], stack_sizes[0]);
	else if (!ft_strcmp(l, "sb"))
		swap_top(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(l, "ss"))
		swap_both(stacks, stack_sizes);
	else if (!ft_strcmp(l, "pa"))
		push_swap(stacks, stack_sizes, 1);
	else if (!ft_strcmp(l, "pb"))
		push_swap(stacks, stack_sizes, 2);
	else if (!ft_strcmp(l, "ra"))
		rotate(stacks[0], stack_sizes[0]);
	else if (!ft_strcmp(l, "rb"))
		rotate(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(l, "rr"))
		rotate_both(stacks, stack_sizes);
	else if (!ft_strcmp(l, "rra"))
		rev_rotate(stacks[0], stack_sizes[0]);
	else if (!ft_strcmp(l, "rrb"))
		rev_rotate(stacks[1], stack_sizes[1]);
	else if (!ft_strcmp(l, "rrr"))
		rev_rotate_both(stacks, stack_sizes);
}

static void	go_high(int stacks[3][MAX_STACK], int sizes[3], int i, int id)
{
	int	biggest;
	int	index;

	while (i != sizes[id] - 1)
	{
		if (id == 0)
		{
			biggest = get_biggest(stacks, sizes, 1);
			index = get_index(stacks[1], sizes[1], biggest);
			if ((sizes[1] - index) <= (sizes[1] / 2))
				select_cmd(stacks, sizes, "rr", 1);
			else
				select_cmd(stacks, sizes, "ra", 1);
		}
		else
			select_cmd(stacks, sizes, "rb", 1);
		i++;
	}
}

static void	go_low(int stacks[3][MAX_STACK], int sizes[3], int i, int id)
{
	int	biggest;
	int	index;

	while (i != sizes[id] - 1 && i >= 0)
	{
		if (id == 0)
		{
			biggest = get_biggest(stacks, sizes, 1);
			index = get_index(stacks[1], sizes[1], biggest);
			if ((sizes[1] - index) > (sizes[1] / 2))
				select_cmd(stacks, sizes, "rrr", 1);
			else
				select_cmd(stacks, sizes, "rra", 1);
		}
		else
			select_cmd(stacks, sizes, "rrb", 1);
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
	if ((sizes[id] - i) > (sizes[id] / 2) + 1)
		go_low(stacks, sizes, i, id);
	else
		go_high(stacks, sizes, i, id);
}
