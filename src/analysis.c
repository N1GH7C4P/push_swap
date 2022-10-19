/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:24 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 18:03:59 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

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
		else
			select_cmd(s, sizes, "rra", 1);
	}
}

int	is_sequenced(int s[3][MAX_STACK], int sizes[3], int id)
{
	int	n;
	int	i;

	n = get_index(s[0], sizes[0], get_biggest(s, sizes, id));
	i = 0;
	while (i < sizes[id] - 2)
	{
		if (n == sizes[id] - 1)
		{
			if (s[id][n] != (s[id][0] + 1) && s[id][n] != (s[id][0]))
				return (0);
			n = 0;
		}
		if (s[id][n] != (s[id][n + 1] + 1) && s[id][n] != (s[id][n + 1]))
			return (0);
		n++;
		i++;
	}
	return (1);
}

int	is_sort(int s[3][MAX_STACK], int sizes[3], int id)
{
	int	i;
	int	top_limiter;

	top_limiter = sizes[id] - 1;
	i = 0;
	while (i < top_limiter)
	{
		if (s[id][i] != (s[id][i + 1] + 1))
			return (0);
		i++;
	}
	return (1);
}

int	count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb)
{
	int	orig_size;
	int	smaller;

	orig_size = stack_size;
	smaller = 0;
	while (orig_size--)
	{
		if (stack[orig_size] < nb)
			smaller++;
	}
	return (smaller);
}

int	count_bits(int n)
{
	int	bits;

	if (n == 0)
		return (0);
	bits = 0;
	while (n != 0)
	{
		n = n / 2;
		bits++;
	}
	bits--;
	return (bits);
}
