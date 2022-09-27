/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/27 18:08:01 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int check_stacks(int stacks[2][MAX_STACK], int stack_sizes[2])
{
	int	i;
	int	prev;

	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return -1;
	prev = -2147483648;
	i =  stack_sizes[0];
	while (i >= 0)
	{
		if (stacks[0][i] < prev)
			return (-1);
		else
			prev = stacks[0][i];
		i--;
	}
	return (1);
}

void print_stacks(int stacks[2][MAX_STACK], int stack_sizes[2])
{
	size_t	i;
	size_t	bigger_stack_size;

	if (stack_sizes[0] > stack_sizes[1])
		bigger_stack_size = stack_sizes[0];
	else
		bigger_stack_size = stack_sizes[1];
	i = bigger_stack_size;
	ft_putendl("-----");
	while (i > 0)
	{
		i--;
		ft_putnbr(stacks[0][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[1][i]);
		ft_putendl("");
	}
	ft_putendl("-----");
	ft_putnbr(stack_sizes[0]);
	ft_putstr(" | ");
	ft_putnbr(stack_sizes[1]);
	ft_putendl("");
	return ;
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