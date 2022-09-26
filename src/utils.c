/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:11 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/26 14:37:20 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int find_smallest_nb_index(int stack[MAX_ARGS], size_t stack_size)
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

void print_stack(int stack[MAX_ARGS], size_t stack_size)
{
	size_t i;

	i = 0;
	while(i < stack_size)
	{
		ft_putnbr(stack[i]);
		ft_putendl("");
		i++;
	}
	return ;
}