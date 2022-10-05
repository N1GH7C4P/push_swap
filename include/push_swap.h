#ifndef CHECKER_H
# define CHECKER_H

# define MAX_ARGS 1000
# define MAX_STACK 2000
# define VERBOSE 0
# include <unistd.h>
# include <stdio.h>

// Preparation
void	rev_stack(int stack[MAX_STACK], int stack_size);
void	rank_stack(int stack[MAX_STACK], int stack_size);
void	copy_stack(int src[MAX_STACK], int dest[MAX_STACK], int stack_size);

// Sorter
void	split_stack_by_bit(int	stacks[3][MAX_STACK], int stack_sizes[3], int bit);
void	radix_sort(int	stacks[3][MAX_STACK], int stack_sizes[3]);
int		is_sort(int stacks[3][MAX_STACK], int stack_sizes[3], int id);

// Utils
void	copy_stack(int	src[MAX_STACK], int	dest[MAX_STACK], int stack_size);
void	print_stacks(int stacks[3][MAX_STACK], int stack_sizes[3]);
void	rank_stack(int	stack[MAX_STACK], int stack_size);
int		count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb);
int		find_smallest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int		find_biggest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int		find_smallest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int		find_biggest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int		find_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id, int nb);
int		count_bits(int n);
int		test_bit(int nb, int bit);
void	clear_stack(int stacks[2][MAX_STACK], int stack_sizes[3], int stack_id);

// Parser
int		parser(int argc, char **argv, int stacks[3][MAX_STACK], int	stack_sizes[2]);
int		parse_input_string(char *input, int stack[MAX_STACK]);
int		parse_arguments(char **argv, int stack[MAX_STACK], int stack_size);

//  Swap commands
void	run_cmd(int stacks[3][MAX_STACK], int stack_sizes[3], char *line, int verbose);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	push_swap(int stacks[3][MAX_STACK], int stack_sizes[3], int direction);
void	swap_top (int stack[MAX_STACK], int stack_size);
void	swap_both(int stacks[3][MAX_STACK], int stack_sizes[3]);
void	rotate(int stack[MAX_STACK], int stack_size);
void	rotate_both(int stacks[3][MAX_STACK], int stack_sizes[3]);
void	rev_rotate(int stack[MAX_STACK], int stack_size);
void	rev_rotate_both(int stacks[3][MAX_STACK], int stack_sizes[3]);

// Higher order commands
void	move_to_top(int stacks[3][MAX_STACK], int stack_sizes[3], int index, int stack_id);

// Complex commands
int		push_biggest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int id);
void	push_all(int stacks[3][MAX_STACK], int stack_sizes[3], int id);

// Getters
int find_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id, int nb);
int find_smallest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int find_smallest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int find_biggest_nb(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int find_biggest_nb_index(int stacks[3][MAX_STACK], int stack_sizes[3], int stack_id);
int count_smaller_numbers(int stack[MAX_STACK], int stack_size, int nb);

#endif