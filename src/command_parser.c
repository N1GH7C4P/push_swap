/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:53:39 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 16:18:06 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	select_cmd(int s[3][MAX_STACK], int sizes[3], char *l, int v)
{
	if (ft_strequ(l, "sa") || ft_strequ(l, "sb") || ft_strequ(l, "ss")
		|| ft_strequ(l, "pa") || ft_strequ(l, "pb") || ft_strequ(l, "ra")
		|| ft_strequ(l, "rb") || ft_strequ(l, "rr") || ft_strequ(l, "rra")
		|| ft_strequ(l, "rrb") || ft_strequ(l, "rrr"))
	{
		if (v)
			ft_putendl(l);
		run_cmd(s, sizes, l);
		return (1);
	}
	else
		return (-1);
}

void	run_cmd(int stacks[3][MAX_STACK], int stack_sizes[3], char *l)
{
	if (ft_strequ(l, "sa"))
		swap_top(stacks[0], stack_sizes[0]);
	else if (ft_strequ(l, "sb"))
		swap_top(stacks[1], stack_sizes[1]);
	else if (ft_strequ(l, "ss"))
		swap_both(stacks, stack_sizes);
	else if (ft_strequ(l, "pa"))
		push_swap(stacks, stack_sizes, 1);
	else if (ft_strequ(l, "pb"))
		push_swap(stacks, stack_sizes, 2);
	else if (ft_strequ(l, "ra"))
		rotate(stacks[0], stack_sizes[0]);
	else if (ft_strequ(l, "rb"))
		rotate(stacks[1], stack_sizes[1]);
	else if (ft_strequ(l, "rr"))
		rotate_both(stacks, stack_sizes);
	else if (ft_strequ(l, "rra"))
		rev_rotate(stacks[0], stack_sizes[0]);
	else if (ft_strequ(l, "rrb"))
		rev_rotate(stacks[1], stack_sizes[1]);
	else if (ft_strequ(l, "rrr"))
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
