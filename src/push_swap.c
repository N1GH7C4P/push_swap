/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:00 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:51 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	split_stack_by_bit(int s[3][MAX_STACK], int sizes[3], int b, int g)
{
	int	i;

	if (is_sequenced(s, sizes, 0) && sizes[1] == 0)
	{
		if (!is_sort(s, sizes, 0) && sizes[1] == 0)
			move_to_top(s, sizes, get_index(s[0], sizes[0],
					get_smallest(s, sizes, 0)), 0);
		exit(1);
	}
	i = find_number_to_push(s, sizes, b, g);
	while (i != -1)
	{
		move_to_top(s, sizes, i, 0);
		if (is_sort(s, sizes, 0) && sizes[1] == 0)
			exit(1);
		select_cmd(s, sizes, "pb", 1);
		i = find_number_to_push(s, sizes, b, g);
	}
}

int	main(int argc, char **argv)
{
	static int	s[3][MAX_STACK];
	static int	sizes[3];

	if (argc < 2 || argc > MAX_ARGS + 1)
		exit_program(0, NULL);
	parser(argc, argv, s, sizes);
	rank_stack(s, sizes, 0);
	if (sizes[0] == 3)
		micro_sort(s, sizes);
	if (sizes[0] < 6)
		mini_sort(s, sizes);
	else
		radix_sort(s, sizes);
}

void	radix_sort(int s[3][MAX_STACK], int szs[3])
{
	int	b;
	int	nb;
	int	i;
	int	g;

	g = 0;
	nb = get_biggest(s, szs, 0);
	b = count_bits(nb);
	while (b)
	{
		split_stack_by_bit(s, szs, b, g);
		nb = get_first_nonzero_index(s, 2);
		i = get_index(s[0], szs[0], nb);
		if (nb != -1)
			move_to_top(s, szs, i, 0);
		push_all(s, szs, 1);
		if (g)
		{
			g = 0;
			b--;
		}
		else
			g = 1;
	}
	move_to_top(s, szs, get_index(s[0], szs[0], get_smallest(s, szs, 0)), 0);
}

void	mini_sort(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	while (!is_sequenced(stacks, stack_sizes, 0))
		push_smallest_nb(stacks, stack_sizes, 0);
	while (!is_sort(stacks, stack_sizes, 0))
		select_cmd(stacks, stack_sizes, "ra", 1);
	while (stack_sizes[1] > 0)
		select_cmd(stacks, stack_sizes, "pa", 1);
}

void	micro_sort(int s[3][MAX_STACK], int sizes[3])
{
	if (!is_sort(s, sizes, 0))
	{
		if (is_sequenced(s, sizes, 0))
		{
			while (!is_sort(s, sizes, 0))
				select_cmd(s, sizes, "ra", 1);
		}
		else if (s[0][0] == 2 && s[0][1] == 3)
		{
			select_cmd(s, sizes, "pb", 1);
			select_cmd(s, sizes, "rra", 1);
			select_cmd(s, sizes, "pa", 1);
		}
		else if (s[0][2] == 3 && s[0][1] == 2)
		{
			select_cmd(s, sizes, "sa", 1);
			select_cmd(s, sizes, "rra", 1);
		}
		else if (s[0][1] == 1 && s[0][0] == 3)
			select_cmd(s, sizes, "sa", 1);
		else
			select_cmd(s, sizes, "rra", 1);
	}
}
