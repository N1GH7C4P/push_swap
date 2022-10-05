/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 16:59:37 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int	count_bits(int n)
{
	int bits;

	if (n == 0)
		return 0;
	bits = 0;
	while (n != 0) {
		n = n / 2;
		bits++;
	}
	return (bits);
}

void print_stack_sizes(int stack_sizes[3])
{
	ft_putnbr(stack_sizes[0]);
	ft_putstr(" | ");
	ft_putnbr(stack_sizes[1]);
	ft_putendl("");
}

void print_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	size_t	i;
	size_t	bigger_stack_size;

	if (stack_sizes[0] > stack_sizes[1])
		bigger_stack_size = stack_sizes[0];
	else
		bigger_stack_size = stack_sizes[1];
	i = 0;
	while (i < bigger_stack_size)
	{	
		ft_putstr("i: ");
		ft_putnbr(i);
		ft_putstr(" | ");
		ft_putnbr(stacks[0][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[1][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[2][i]);
		ft_putendl("");
		i++;
	}
}

 void exit_program(int error)
{
	if (error)
	{
		ft_putendl("Error");
		exit(-1);
	}
	exit(0);
}

int	test_bit(int nb, int bit)
{
	return (nb & (1 << bit));
}

void	clear_stack(int stacks[2][MAX_STACK], int stack_sizes[3], int stack_id)
{
	int i;

	i = 0;
	while (i < MAX_STACK)
	{
		stacks[stack_id][i] = 0;
		i++;
	}
	stack_sizes[stack_id] = 0;
}
