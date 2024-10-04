/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:02:21 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 07:25:57 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes
# include "libft.h"
# include "structs.h"
# include "testers.h"

// Defines
# define TRUE (int)1
# define FALSE (int)0

# define STACK_A 1
# define STACK_B 0

# define ROTATE 0
# define REVERSE_ROTATE 1
# define SWAP 1
# define PUSH 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648
// Tests
int			main_test_cost_sorting_nbr(void);

// Args Management
t_stack		*strings_to_stack(char **strs);
t_stack		*parse_string_argument(char *arg);
t_stack		*parse_arguments(char **args);

//Cost Management
void		cost_sorting_nbr(t_stack *stack_a, t_stack *stack_b, int nbr, t_cost *c);
void		cost_push_best(t_stack **a, t_stack **b, t_cost *cost);

//Sorting Logic:
void		push_back_to_a(t_stack **stack_a, t_stack **stack_b);
int			main_loop(t_stack **stack_a, t_stack **stack_b);
int			sort_three_a(t_stack **stack_a, t_stack **stack_b);
int			end_sort_three_a(t_stack **stack_a, t_stack **stack_b, int y, int z);

// Rotation Functions

void		rotate_to_top_a(t_stack **stack_a, int target);
void		rotate_to_top_b(t_stack **stack_b, int target);
void		rotate_n_time(t_stack **stack, int n, int which_stack);
void		reverse_rotate_n_time(t_stack **stack, int n, int which_stack);
void		double_rotate(t_stack **a, t_stack **b, t_cost *cost);
void		rev_double_rotate(t_stack **a, t_stack **b, t_cost *cost);
void		do_which_rotation(t_stack **stack, int rotation, int which_stack);

//Stack Manipulation / Simulation
int			do_pa(t_stack **stack_a, t_stack **stack_b);
int			do_pb(t_stack **stack_a, t_stack **stack_b);
int			do_ra(t_stack **stack_a);
int			do_rb(t_stack **stack_b);
int			do_rra(t_stack **stack_a);
int			do_rrb(t_stack **stack_b);
int			do_rrr(t_stack **stack_a, t_stack **stack_b);
int			do_rr(t_stack **stack_a, t_stack **stack_b);
int			do_sa(t_stack *stack_a);
int			do_sb(t_stack *stack_b);
int			do_ss(t_stack *stack_a, t_stack *stack_b);
int			sim_ss(t_stack *stack_a, t_stack *stack_b);
int			sim_sa(t_stack *stack_a);
int			sim_sb(t_stack *stack_b);
int			sim_ra(t_stack **stack_a);
int			sim_rb(t_stack **stack_b);
int			sim_rra(t_stack **stack_a);
int			sim_rrb(t_stack **stack_b);
int			sim_rr(t_stack **stack_a, t_stack **stack_b);
int			sim_rrr(t_stack **stack_a, t_stack **stack_b);
int			sim_pa(t_stack **stack_a, t_stack **stack_b);
int			sim_pb(t_stack **stack_a, t_stack **stack_b);

// For tests
//t_stack	*create_stack(int *values, int size);
int	test_lis(int argc, char **argv);

// Smart Moves
void		smart_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void		doing_the_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void		push_min(t_stack **stack_a, t_stack **stack_b, int which);
void		push_max(t_stack **stack_a, t_stack **stack_b, int which);
void		push_range_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max);
void		push_range_to_a(t_stack **stack_a, t_stack **stack_b, int min, int max);
int			*find_lis(t_stack *stack_a, int *lis_length);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);

// Search & Utility Functions
int			find_minimum(t_stack *stack);
int			find_maximum(t_stack *stack);
int			find_insert_position(t_stack *stack_b, int nbr);
t_search	*initialize_search(void);
void		update_search(t_search *search, int range, int approx, int highest);
void		update_highest_tryable(t_stack **stack_b, t_search *search);
int			stackfind(t_stack *stack, int target);
int			stack_length(t_stack *lst);
int			sqrt_int(int number);
t_stack		*get_nth_node(t_stack *stack, int n);
void		numberize_stack_numbers(t_stack *stack_a);
void		clear_stack(t_stack **stack);
t_stack		*stackdup(t_stack *lst);
t_stack		*stacknew(int value);
void		print_t_cost(t_cost *cost);
int			is_in_lis(int nbr, int *lis, int lis_length);
void		print_lis(int *lis, int lis_length);
t_cost		*t_cost_dup(t_cost *original);
void		print_tstack(t_stack *lst);
#endif