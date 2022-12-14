/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:55 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_sizes(int stack_sizes[3])
{
	ft_putnbr(stack_sizes[0]);
	ft_putstr(" | ");
	ft_putnbr(stack_sizes[1]);
	ft_putendl("");
}

void	print_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	size_t	i;
	size_t	bigger_stack_size;

	if (stack_sizes[0] > stack_sizes[1])
		bigger_stack_size = stack_sizes[0] + 1;
	else
		bigger_stack_size = stack_sizes[1] + 1;
	i = 0;
	while (i < bigger_stack_size)
	{
		ft_putnbr(stacks[0][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[1][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[2][i]);
		ft_putendl("");
		i++;
	}
}

void	exit_program(int ret, char *msg)
{
	if (msg && DESCRIPTIVE_MESSAGES == 1)
		ft_putendl(msg);
	else if (ret == -1)
		ft_putendl_fd("Error", 2);
	exit(ret);
}

int	test_bit(int nb, int bit)
{
	return (nb & (1 << bit));
}

void	clear_stack(int stacks[2][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int	i;

	i = 0;
	while (i < MAX_STACK)
	{
		stacks[stack_id][i] = 0;
		i++;
	}
	stack_sizes[stack_id] = 0;
}
