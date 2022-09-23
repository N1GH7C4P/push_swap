/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/23 12:54:23 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int	check_argument(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if(input[i] < '0' || input[i] > 9)
			return (0);
		i++;
	}
	return (1);
}

int find_smallest_nb_index(int stack[max_args], size_t stack_size)
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

void print_stack()
{

}

int check_stack(int stack[max_args], size_t stack_size)
{
	size_t	i;
	int		prev;

	prev = -2147483648;
	i = 0;
	while (i < stack_size)
	{
		ft_putstr("i: ");
		ft_putnbr(i);
		ft_putendl("");
		ft_putstr("prev: ");
		ft_putnbr(prev);
		ft_putendl("");
		ft_putstr("stack[i]: ");
		ft_putnbr(stack[i]);
		ft_putendl("");
		if (stack[i] < prev)
			return (-1);
		else
			prev = stack[i];
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static int	stack[max_args];
	size_t		i;

	i = 0;
	while (argv[i])
	{
		if (check_argument(argv[i]) == -1)
		{
			ft_putendl("Error");
			return (-1);
		}
		else
			stack[i] = ft_atoi(argv[1]);
		i++;
	}
	if (check_stack(stack, i) == -1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (argc);
}
