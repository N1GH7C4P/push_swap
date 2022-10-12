/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:00 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/11 15:32:05 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	s_sizes[2];

	if (argc < 2)
		exit_program(0, NULL);
	parser(argc, argv, stacks, s_sizes);
	//print_stacks(stacks, s_sizes);
	rank_stack(stacks[0], s_sizes[0]);
	radix_sort(stacks, s_sizes);
}

static int	find_first_nonzero_index(int stacks[3][MAX_STACK], int id)
{
	int	i;

	i = 0;
	while (i < MAX_STACK)
	{
		if (stacks[id][i] != 0)
			return (i);
		i++;
	}
	return (-1);
}

void	radix_sort(int s[3][MAX_STACK], int s_sizes[3])
{
	int	bit;
	int	nb;
	int	i;

	nb = get_biggest(s, s_sizes, 0);
	bit = count_bits(nb);
	while (bit--)
	{
		split_stack_by_bit(s, s_sizes, bit);
		nb = find_first_nonzero_index(s, 2);
		i = get_index(s, s_sizes, 0, nb);
		if (nb != -1)
			move_to_top(s, s_sizes, i, 0);
		push_all(s, s_sizes, 1);
	}
	move_to_top(s, s_sizes, get_index(s, s_sizes, 0, get_smallest(s, s_sizes, 0)), 0);
}

int	find_number_to_push(int stacks[3][MAX_STACK], int s_sizes[3], int bit)
{
	int	orig_size;
	int	nb;

	orig_size = s_sizes[0];
	while (orig_size)
	{
		nb = stacks[0][orig_size - 1];
		if (test_bit(nb, bit) && stacks[2][nb - 1] < 1)
			return (orig_size - 1);
		orig_size--;
	}
	return (-1);
}

void	split_stack_by_bit(int s[3][MAX_STACK], int s_sizes[3], int bit)
{
	int	i;

	if (is_sort(s, s_sizes, 0))
		exit(1);
	i = find_number_to_push(s, s_sizes, bit);
	while (i != -1)
	{
		move_to_top(s, s_sizes, i, 0);
		if (is_sort(s, s_sizes, 0))
			exit(1);
		run_cmd(s, s_sizes, "pb", 1);
		i = find_number_to_push(s, s_sizes, bit);
	}
}
