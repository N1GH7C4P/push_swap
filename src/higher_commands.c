/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:58:39 by kpolojar          #+#    #+#             */
/*   Updated: 2022/12/09 17:38:40 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_both(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	swap_top(stacks[0], stack_sizes[0]);
	swap_top(stacks[1], stack_sizes[1]);
}

void	rotate_both(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	rotate(stacks[0], stack_sizes[0]);
	rotate(stacks[1], stack_sizes[1]);
}

void	rev_rotate_both(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	rev_rotate(stacks[0], stack_sizes[0]);
	rev_rotate(stacks[1], stack_sizes[1]);
}
