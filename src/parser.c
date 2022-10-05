/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:35 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 16:55:23 by kpolojar         ###   ########.fr       */
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
		if (!ft_isdigit(input[i]))
		{
			ft_putstr("Invalid digit: ");
			ft_putchar(input[i]);
			free(input);
			exit_program(-1);
		}
		i++;
	}
	return (1);
}

int	parser(int argc, char **argv, int stacks[3][MAX_STACK], int stack_sizes[2])
{
	char		*line;

	line = NULL;
	if (argc > MAX_ARGS - 1)
		exit_program(1);
	if (argc == 2)
		stack_sizes[0] = parse_input_string(argv[1], stacks[0]);
	else
		stack_sizes[0] = parse_arguments(argv, stacks[0], argc - 1);
	if (stack_sizes[0] < 0)
		exit_program(1);
	free(line);
	return (0);
}

int	parse_input_string(char *input, int stack[MAX_STACK])
{
	int	i;
	int	nb_count;
	int	nb;

	i = 0;
	nb_count = 0;
	while (input[i])
	{
		while (ft_iswhitespace(input[i]))
			i++;
		if (!ft_isdigit(input[i]))
		{
			ft_putstr("Invalid digit: ");
			ft_putchar(input[i]);
			exit_program(-1);
		}
		nb = ft_atoi(input + i);
		stack[++nb_count - 1] = nb;
		i += ft_countdigits(nb, 10);
	}
	rev_stack(stack, nb_count);
	return (nb_count);
}

int	parse_arguments(char **argv, int stack[MAX_STACK], int stack_size)
{
	int	i;

	i = stack_size;
	while (argv[i] && i > 0)
	{
		if (check_argument(argv[i]) == -1)
			return (-1);
		else
			stack[i - 1] = ft_atoi(argv[i]);
		i--;
	}
	rev_stack(stack, stack_size);
	return (stack_size);
}
