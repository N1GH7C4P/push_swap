/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:00 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 17:22:08 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	static int	s[3][MAX_STACK];
	static int	sizes[3];

	if (argc < 2)
		exit_program(0, NULL);
	parser(argc, argv, s, sizes);
	rank_stack(s, sizes, 0);
	if (sizes[0] == 3)
		micro_sort(s, sizes);
	else if (sizes[0] < 6)
		mini_sort(s, sizes);
	else
		radix_sort(s, sizes);
}

static int	find_first_nonzero_index(int s[3][MAX_STACK], int id)
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

void	radix_sort(int s[3][MAX_STACK], int sizes[3])
{
	int	b;
	int	nb;
	int	i;
	int	g;

	g = 0;
	nb = get_biggest(s, sizes, 0);
	b = count_bits(nb);
	while (b)
	{
		split_stack_by_bit(s, sizes, b, g);
		nb = find_first_nonzero_index(s, 2);
		i = get_index(s[0], sizes[0], nb);
		if (nb != -1)
			move_to_top(s, sizes, i, 0);
		push_all(s, sizes, 1);
		if (g)
		{
			g = 0;
			b--;
		}
		else
			g = 1;
	}
	move_to_top(s, sizes, get_index(s[0], sizes[0], get_smallest(s, sizes, 0)), 0);
}

static int	find_number_to_push(int s[3][MAX_STACK], int sizes[3], int b, int g)
{
	int	orig_size;
	int	nb;
	int	m;

	orig_size = sizes[0];
	m = get_radix_median(b);
	while (orig_size)
	{
		nb = s[0][orig_size - 1];
		if (g == 1)
		{
			if (test_bit(nb, b) && s[2][nb] < 1 && (nb <= m || m <= 100))
				return (orig_size - 1);
		}
		else
		{
			if (test_bit(nb, b) && s[2][nb] < 1 && (nb > m || m <= 100))
				return (orig_size - 1);
		}
		orig_size--;
	}
	return (-1);
}

void	split_stack_by_bit(int s[3][MAX_STACK], int sizes[3], int b, int g)
{
	int	i;
	
	if (is_sequenced(s, sizes, 0) && sizes[1] == 0)
	{
		if (!is_sort(s, sizes, 0) && sizes[1] == 0)
			move_to_top(s, sizes, get_index(s[0], sizes[0], get_smallest(s, sizes, 0)), 0);
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

void	mini_sort(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	while (!is_sequenced(stacks, stack_sizes, 0))
		push_smallest_nb(stacks, stack_sizes, 0);
	while (!is_sort(stacks, stack_sizes, 0))
		select_cmd(stacks, stack_sizes, "ra", 1);
	while (stack_sizes[1] > 0)
		select_cmd(stacks, stack_sizes, "pa", 1);
}
