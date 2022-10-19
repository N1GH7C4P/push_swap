/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/19 15:44:01 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	stack_sizes[2];
	int			ret;
	char		*line;

	if (argc < 2)
		return (0);
	parser(argc, argv, stacks, stack_sizes);
	rank_stack(stacks, stack_sizes, 0);
	line = NULL;
	ret = ft_get_next_line(0, &line);
	while (ret == 1 && ft_strcmp(line, "") && ft_strcmp(line, "\n"))
	{
		select_cmd(stacks, stack_sizes, line, 0);
		ret = ft_get_next_line(0, &line);
	}
	if (check_stacks(stacks, stack_sizes) != 1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free(line);
	exit_program(0, NULL);
}

int		check_stacks(int stacks[2][MAX_STACK], int stack_sizes[3])
{
	if (stack_sizes[0] < 0 || stack_sizes[1] > 0)
		return (-1);
	if (is_sort(stacks, stack_sizes, 0))
		return (1);
	return (0);
}
