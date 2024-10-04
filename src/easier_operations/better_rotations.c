/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:19:54 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 12:53:36 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Will do rr since they both need to rotate, then ra or rb for the rest
static void	double_rotate(t_stack **a, t_stack **b, t_cost *cost)
{
	int	both;

	if (cost->a_rotations < cost->b_rotations)
		both = cost->a_rotations;
	else
		both = cost->b_rotations;
	while (both-- > 0)
	{
		cost->a_rotations--;
		cost->b_rotations--;
		do_rr(a, b);
	}
	while (cost->a_rotations-- > 0)
		do_ra(a);
	while (cost->b_rotations-- > 0)
		do_rb(b);
}

// Will do rrr since they both need to reve rotate, then rra or rrb for the rest
static void	rev_double_rotate(t_stack **a, t_stack **b, t_cost *cost)
{
	int	both;

	if (!cost)
		return ;
	if (cost->a_rotations < cost->b_rotations)
		both = cost->a_rotations;
	else
		both = cost->b_rotations;
	while (both > 0)
	{
		do_rrr(a, b);
		both--;
	}
	while (cost->a_rotations > cost->b_rotations)
	{
		do_rra(a);
		cost->a_rotations--;
	}
	while (cost->b_rotations > cost->a_rotations)
	{
		do_rrb(b);
		cost->b_rotations--;
	}
}

void	same_doing_what(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (cost->doing_what_a == ROTATE)
		double_rotate(stack_a, stack_b, cost);
	else
		rev_double_rotate(stack_a, stack_b, cost);
	do_pb(stack_a, stack_b);
}

void	rotate_n_time(t_stack **stack, int n, int which_stack)
{
	if (which_stack == STACK_A)
		while (n-- > 0)
			do_ra(stack);
	else if (which_stack == STACK_B)
		while (n-- > 0)
			do_rb(stack);
}

void	reverse_rotate_n_time(t_stack **stack, int n, int which_stack)
{
	if (which_stack == STACK_A)
		while (n-- > 0)
			do_rra(stack);
	else if (which_stack == STACK_B)
		while (n-- > 0)
			do_rrb(stack);
}
