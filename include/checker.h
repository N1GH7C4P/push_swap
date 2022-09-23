/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:28:41 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/23 12:12:19 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define max_args 1000
# include <unistd.h>

int	check_argument(char *input);
int	find_smallest_nb_index(int stack[max_args], size_t stack_size);

#endif
