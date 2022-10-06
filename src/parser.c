/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:35 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/06 17:04:10 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static int	check_argument(char *input)
{
	size_t	i;

	if (atoi(input) == INT_MIN || atoi(input) == INT_MAX)
		exit_program(-1, "INT_MIN & INT MAX not supported.");
	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			exit_program(-1,"Invalid digit.");
		i++;
	}
	return (1);
}

int	parser(int argc, char **argv, int stacks[3][MAX_STACK], int stack_sizes[2])
{
	if (argc > MAX_ARGS - 1)
		exit_program(-1, "Too many arguments.");
	if (argc == 2)
		stack_sizes[0] = parse_input_string(argv[1], stacks[0]);
	else
		stack_sizes[0] = parse_arguments(argv, stacks[0], argc - 1, 0);
	return (0);
}

int	parse_input_string(char *input, int stack[MAX_STACK])
{
	int	word_count;
	char **words;

	words = ft_strsplit(input, ' ');
	word_count = 0;
	while (words[word_count])
		word_count++;
	parse_arguments(words, stack, word_count, 0);
	return (word_count);
}

int	parse_arguments(char **argv, int stack[MAX_STACK], int stack_size, int skip_first)
{
	int	i;
	
	i = stack_size;
	if (skip_first == 0)
		i--;
	while (argv[i])
	{
		if (skip_first == 0 && i == 0)
			break ;
		else if (check_argument(argv[i]) == -1)
			return (-1);
		else
			stack[i - 1] = ft_atoi(argv[i]);
		i--;
	}
	rev_stack(stack, stack_size);
	return (stack_size);
}
