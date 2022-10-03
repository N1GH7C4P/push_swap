/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/30 15:09:26 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int check_stacks(int stacks[3][MAX_STACK], int stack_sizes[2], int verbose)
{
	int	i;
	int	prev;

	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
	{
		if (verbose)
			ft_putendl("Invalid stack sizes");
		return -1;
	}
	prev = INT_MAX;
	i =  0;
	while (i < stack_sizes[0])
	{
		if (stacks[0][i] > prev)
		{
			if (verbose)
			{
				ft_putnbr(stacks[0][i]);
				ft_putstr(" > ");
				ft_putnbr(prev);
				ft_putendl("");
			}
			return (-1);
		}
		else
			prev = stacks[0][i];
		i++;
	}
	return (1);
}

void print_stacks(int stacks[3][MAX_STACK], int stack_sizes[2])
{
	size_t	i;
	size_t	bigger_stack_size;

	if (stack_sizes[0] > stack_sizes[1])
		bigger_stack_size = stack_sizes[0];
	else
		bigger_stack_size = stack_sizes[1];
	i = 0;
	ft_putendl("-----");
	while (i < bigger_stack_size)
	{
		ft_putnbr(stacks[0][i]);
		ft_putstr(" | ");
		ft_putnbr(stacks[1][i]);
		ft_putendl("");
		i++;
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