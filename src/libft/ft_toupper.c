/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:46:41 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/11 12:56:55 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int nb)
{
	if (nb >= 97 && nb <= 122)
		return (nb - 32);
	return (nb);
}