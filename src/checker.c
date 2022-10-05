/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/05 16:59:17 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int	check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	int	i;
	int	prev;

	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return -1;
	prev = INT_MAX;
	i =  0;
	while (i < stack_sizes[0])
	{
		if (stacks[0][i] > prev)
			return (-1);
		else
			prev = stacks[0][i];
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	stack_sizes[2];
	int			ret;
	char		*line;

	parser(argc, argv, stacks, stack_sizes);
	print_stacks(stacks, stack_sizes);
	line = NULL;
	ret = ft_get_next_line(0, &line);
	while (ret == 1 && ft_strcmp(line, "") && ft_strcmp(line, "\n"))
	{
		run_cmd(stacks, stack_sizes, line, 0);
		ret = ft_get_next_line(0, &line);
	}
	print_stacks(stacks, stack_sizes);
	if (check_stacks(stacks, stack_sizes) == -1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free(line);
	exit_program(0);
}
