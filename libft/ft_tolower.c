/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:57:30 by kpolojar          #+#    #+#             */
/*   Updated: 2021/11/11 12:58:54 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int nb)
{
	if (nb >= 65 && nb <= 90)
		return (nb + 32);
	return (nb);
}