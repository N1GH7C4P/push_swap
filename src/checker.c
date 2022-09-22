/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:19 by kpolojar          #+#    #+#             */
/*   Updated: 2022/09/22 16:34:45 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define max_args 1000

int	check_argument(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if(input[i] < '0' || input[i] > 9)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		nums[max_args];
	int		i;

	i = 0;
	while (argv[i])
	{
		if(!check_argument(argv[i]))
		{
			ft_putendl("Error");
			return(-1);
		}
		else
			nums[i] = ft_atoi(argv[1]);
		i++;
	}
	return (0);
}