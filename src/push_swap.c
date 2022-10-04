#include "../include/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	static int	stacks[3][MAX_STACK];
	static int	stack_sizes[2];

	parser(argc, argv, stacks, stack_sizes);
	rank_stack(stacks[0], stack_sizes[0]);
	radix_sort(stacks, stack_sizes);
	//print_stacks(stacks, stack_sizes);
}

// direction (0) => A -> B, direction (1) => B -> A
int	push_biggest_nb_on_stack(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	int index;
	int nb;

	index = find_biggest_nb_index(stacks, stack_sizes, 1);
	if (VERBOSE)
	{
		ft_putstr("biggest index: ");
		ft_putnbr(index);
		ft_putstr(" nb: ");
		ft_putnbr(stacks[1][index]);
		ft_putstr(" stack_size: ");
		ft_putnbr(stack_sizes[1]);
		ft_putendl("");
	}
	if (index != -1)
	{
		move_to_top(stacks, stack_sizes, index, 1);
		nb = stacks[1][stack_sizes[1] - 1];
		run_command(stacks, stack_sizes, "pa", 1);
		return (nb);
	}
	return (-1);
}

void move_to_top(int stacks[3][MAX_STACK], int stack_sizes[3], int index, int stack_id)
{
	if (stack_sizes[stack_id] < 2)
		return ;
	if (index > stack_sizes[stack_id])
	{
		ft_putendl("invalid index: ");
		ft_putnbr(index);
		ft_putstr(" > ");
		ft_putnbr(stack_sizes[stack_id]);
		ft_putendl("");
		exit(-1);
	}
	if ((stack_sizes[stack_id] - index) > (stack_sizes[stack_id] / 2))
	{
		while (index != stack_sizes[stack_id] - 1)
		{
			if (stack_id == 0)
				run_command(stacks, stack_sizes, "rra", 1);
			else
				run_command(stacks, stack_sizes, "rrb", 1);
			if (index == 0)
				index = stack_sizes[stack_id] - 1;
			else
				index--;
		}
	}
	else
	{
		while (index != stack_sizes[stack_id] - 1)
		{
			if (VERBOSE)
			{
				ft_putstr("index: ");
				ft_putnbr(index);
				ft_putstr(" stack size: ");
				ft_putnbr(stack_sizes[stack_id]);
				ft_putendl("");
			}
			if (stack_id == 0)
				run_command(stacks, stack_sizes, "ra", 1);
			else
				run_command(stacks, stack_sizes, "rb", 1);
			index++;
		}
	}
}

void copy_stack(int	src[MAX_STACK], int	dest[MAX_STACK], int stack_size)
{
	int orig_size = stack_size;
	while (orig_size--)
		dest[orig_size] = src[orig_size];
}

void rank_stack(int	stack[MAX_STACK], int stack_size)
{
	int	ranked[MAX_STACK];
	int orig_stack_size;
	int smaller;

	orig_stack_size = stack_size;
	while (orig_stack_size--)
	{
		smaller = count_smaller_numbers(stack, stack_size, stack[orig_stack_size]);
		ranked[orig_stack_size] = smaller + 1; 
	}
	copy_stack(ranked, stack, stack_size);
}

void radix_sort(int	stacks[3][MAX_STACK], int stack_sizes[3])
{
	int	bit;
	int	nb;
	int	index;

	nb = find_biggest_nb(stacks, stack_sizes, 0);
	bit = count_bits(nb);
	if (VERBOSE)
	{
		ft_putstr("bits: ");
		ft_putnbr(bit);
		ft_putendl("");
	}
	while (bit--)
	{
		if(VERBOSE)
			ft_putendl("Splitting stack B.");
		split_stack_by_bit(stacks, stack_sizes, bit);
		nb = find_smallest_nb(stacks, stack_sizes, 2);
		index = find_nb_index(stacks, stack_sizes, 0, nb);
		if (VERBOSE)
		{
			ft_putstr("Smallest returned number: ");
			ft_putnbr(nb);
			ft_putstr(" index: ");
			ft_putnbr(index);
			ft_putendl("");
		}
		if (nb != -1)
			move_to_top(stacks, stack_sizes, index, 0);
		if(VERBOSE)
			ft_putendl("Returning all to A stack.");
		return_all_to_stack_a(stacks, stack_sizes);
	}
}

int find_number_to_push(int stacks[3][MAX_STACK], int stack_sizes[3], int bit)
{
	int orig_stack_size;
	int nb;
	
	orig_stack_size = stack_sizes[0];
	while (orig_stack_size)
	{
		nb = stacks[0][orig_stack_size - 1];
		if (test_bit(nb, bit) && stacks[2][nb - 1] < 1)
		{
			if (VERBOSE)
				ft_putnbr(test_bit(stacks[0][orig_stack_size - 1], bit));
			if (stacks[2][stacks[0][stack_sizes[0] - 2]] == 1 && stacks[0][stack_sizes[0] - 1] == (stacks[0][stack_sizes[0] - 2] + 1))
			{
				stacks[2][stacks[0][stack_sizes[0] - 1]] = 1;
				continue ;
			}
			return (orig_stack_size - 1);
		}
		orig_stack_size--;
	}
	return (-1);
}

void split_stack_by_bit(int	stacks[3][MAX_STACK], int stack_sizes[3], int bit)
{
	int index;

	index = find_number_to_push(stacks, stack_sizes, bit);
	while (index != -1)
	{
		move_to_top(stacks, stack_sizes, index, 0);
		run_command(stacks, stack_sizes, "pb", 1);
		index = find_number_to_push(stacks, stack_sizes, bit);
	}
}

void	return_all_to_stack_a(int stacks[3][MAX_STACK], int stack_sizes[3])
{
	int ret;

	ret = push_biggest_nb_on_stack(stacks, stack_sizes);
	while (ret != -1)
	{
		ret = push_biggest_nb_on_stack(stacks, stack_sizes);
		stacks[2][ret] = 1;
		stack_sizes[2] = stack_sizes[2] + 1;
	}
	clear_stack(stacks, stack_sizes, 1);
}
