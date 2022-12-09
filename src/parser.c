/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:35 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 16:30:44 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static int	check_argument(char *input)
{
	size_t	i;

	i = 0;
	if ((!ft_strcmp(input, "-") && !ft_strcmp(input, "+"))
		|| ft_strequ(input, ""))
		exit_program(-1, "Invalid digit.");
	if (input[i] == '-' || input[i] == '+')
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
	if (argc > MAX_ARGS + 1)
		exit_program(-1, "Wrong number of arguments.");
	if (argc == 2)
		sizes[0] = parse_input_string(argv[1], stacks[0]);
	else
		sizes[0] = parse_arguments(argv, stacks[0], argc - 1, 1);
	rev_stack(stacks[0], sizes[0]);
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
	ft_free_array(words);
	return (word_count);
}

int	parse_arguments(char **argv, int stack[MAX_STACK], int size, int skip_first)
{
	int	i;
	int	index;
	int	zero;

	i = 0;
	zero = 0;
	if (skip_first == 1)
		i++;
	while (argv[i])
	{
		check_argument(argv[i]);
		index = -1;
		if (ft_atoi(argv[i]) == 0)
			zero++;
		else
			index = get_index(stack, size, ft_atoi(argv[i]));
		if (index != -1 || zero > 1)
			exit_program(-1, "Duplicate values.");
		stack[i - skip_first] = ft_atoi(argv[i]);
		i++;
	}
	return (size);
}
