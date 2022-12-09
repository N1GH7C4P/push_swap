/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:18 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_output(int code)
{
	if (code != 1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
}

int	main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	stack_sizes[2];
	int			ret;
	char		*line;

	if (argc < 2 || argc > MAX_ARGS + 1
		|| (argc == 2 && ft_strequ("", argv[1])))
		return (0);
	parser(argc, argv, stacks, stack_sizes);
	rank_stack(stacks, stack_sizes, 0);
	line = NULL;
	ret = ft_get_next_line(0, &line);
	while (ret == 1)
	{
		if (select_cmd(stacks, stack_sizes, line, 0) == -1)
			stacks[2][MAX_STACK - 1] = -1;
		free(line);
		ret = ft_get_next_line(0, &line);
	}
	if (stacks[2][MAX_STACK - 1] == -1)
		exit_program(-1, "Error");
	print_output(check_stacks(stacks, stack_sizes));
	exit_program(0, NULL);
}

int	check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return (-1);
	if (is_sort(stacks, stack_sizes, 0))
		return (1);
	return (0);
}
