/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/10/11 14:53:03 by kpolojar         ###   ########.fr       */
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

	parser(argc, argv, stacks, stack_sizes);
	line = NULL;
	ret = ft_get_next_line(0, &line);
	while (ret == 1 && ft_strcmp(line, "") && ft_strcmp(line, "\n"))
	{
		run_cmd(stacks, stack_sizes, line, 0);
		ret = ft_get_next_line(0, &line);
	}
	if (check_stacks(stacks, stack_sizes) == -1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free(line);
	exit_program(0, NULL);
}
