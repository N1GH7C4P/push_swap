/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/26 15:14:46 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

static int	check_argument(char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if(input[i] < '0' || input[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

static int	parse_input_string(char *input, int stack[MAX_STACK])
{
	int	i;
	int	nb_count;
	int nb;

	i = 0;
	nb_count = 0;
	while (input[i])
	{
		while (ft_iswhitespace(input[i]))
			i++;
		if (!ft_isdigit(input[i]))
			return (-1);
		nb = ft_atoi(input + i);
		stack[++nb_count - 1] = nb;
		i += ft_countdigits(nb, 10);
	}
	return (nb_count);
}

int parse_arguments(char **argv, int stack[MAX_STACK])
{
	int stack_size;

	stack_size = 0;
	while (argv[stack_size + 1])
	{
		if (check_argument(argv[stack_size + 1]) == -1)
			return (-1);
		else
			stack[stack_size] = ft_atoi(argv[stack_size + 1]);
		stack_size++;
	}
	return (stack_size);
}

static int check_stack(int stack[MAX_STACK], int stack_size)
{
	int	i;
	int	prev;

	if (stack_size < 0)
		return -1;
	prev = -2147483648;
	i = 0;
	while (i < stack_size)
	{
		if (stack[i] < prev)
			return (-1);
		else
			prev = stack[i];
		i++;
	}
	return (1);
}

static void exit_program(int error)
{
	if (error)
	{
		ft_putendl("Error");
		exit(-1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	static int	stacks[2][MAX_STACK];
	int			stack_sizes[2];
	char		*line;
	int			ret;
	
	line = NULL;
	if (argc > MAX_ARGS - 1)
		exit_program(1);
	if (argc == 2)
		stack_sizes[0] = parse_input_string(argv[1], stacks[0]);
	else
		stack_sizes[0] = parse_arguments(argv, stacks[0]);
	if (stack_sizes[0] < 0)
		exit_program(1);
	else
	{
		ret = ft_get_next_line(0, &line);
		if (ret)
			run_command(stacks[0], stack_sizes[0], line);
		print_stack(stacks[0], stack_sizes[0]);
		if (check_stack(stacks[0], stack_sizes[0]) == -1)
			ft_putendl("KO");
		else
			ft_putendl("OK");
	}
	free(line);
	exit_program(0);
}
