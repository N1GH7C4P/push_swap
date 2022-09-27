/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/27 15:53:43 by kpolojar         ###   ########.fr       */
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

int find_smallest_nb_index(int stack[MAX_STACK], size_t stack_size)
{
	size_t		i;
	int			smallest;
	int			index_smallest;

	smallest = 2147483647;
	i = 0;
	while (i < stack_size)
	{
		if (stack[i] <= smallest)
		{
			smallest = stack[i];
			index_smallest = i;
		}
		i++;
	}
	return (index_smallest);
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
	while(i > 0)
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