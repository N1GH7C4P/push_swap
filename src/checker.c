/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/27 16:12:54 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	static int	stacks[2][MAX_STACK];
	static int	stack_sizes[2];
	int			ret;
	char		*line;

	parser(argc, argv, stacks, stack_sizes);
	line = NULL;
	ret = ft_get_next_line(0, &line);
	while (ret && strcmp(line, ""))
	{
		run_command(stacks, stack_sizes, line);
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
