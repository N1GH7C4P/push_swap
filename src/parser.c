/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:35 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/17 18:38:25 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static int	check_argument(char *input)
{
	size_t	i;

	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			exit_program(-1, "Invalid digit.");
		i++;
	}
	return (1);
}

int	parser(int argc, char **argv, int stacks[3][MAX_STACK], int sizes[2])
{
	if (argc > MAX_ARGS - 1)
		exit_program(-1, "Too many arguments.");
	if (argc == 2)
		sizes[0] = parse_input_string(argv[1], stacks[0]);
	else
		sizes[0] = parse_arguments(argv, stacks[0], argc - 1, 1);
	return (0);
}

int	parse_input_string(char *input, int stack[MAX_STACK])
{
	int		word_count;
	char	**words;

	words = ft_strsplit(input, ' ');
	word_count = 0;
	while (words[word_count])
		word_count++;
	parse_arguments(words, stack, word_count, 0);
	return (word_count);
}

int	parse_arguments(char **argv, int stack[MAX_STACK], int size, int skip_first)
{
	int	i;
	int	index;
	int nb;

	i = 0;
	if (skip_first == 1)
		i++;
	while (argv[i])
	{
		if (check_argument(argv[i]) == -1)
			exit_program(-1, "Invalid argument!");
		else
		{
			nb = ft_atoi(argv[i]);
			index = get_index(stack, size, nb);
			if (index != -1)
				exit_program(-1, "Duplicate value!");
			stack[i - skip_first] = nb;
		}
		i++;
	}
	rev_stack(stack, size);
	return (size);
}
