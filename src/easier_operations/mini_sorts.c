/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:07:32 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/11 16:39:03 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_sort_three_a(t_stack **stack_a, t_stack **stack_b, int y, int z)
{
	if (y < z && z < (*stack_a)->value)
	{
		do_pb(stack_a, stack_b);
		do_pb(stack_a, stack_b);
		do_ra(stack_a);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
		do_rra(stack_a);
	}
	else if ((*stack_a)->value < z && z < y)
	{
		do_pb(stack_a, stack_b);
		do_ra(stack_a);
		do_pb(stack_a, stack_b);
		do_rra(stack_a);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
	}
	return (0);
}

int	sort_three_a(t_stack **stack_a, t_stack **stack_b)
{
	int	y;
	int	z;

	y = (*stack_a)->next->value;
	z = (*stack_a)->next->next->value;
	if ((*stack_a)->value < y && y < z)
		return (0);
	else if (y < (*stack_a)->value && (*stack_a)->value < z)
		do_sa(*stack_a);
	else if (z < y && y < (*stack_a)->value)
	{
		do_pb(stack_a, stack_b);
		rotate_n_time(stack_a, 2, STACK_A);
		do_pa(stack_a, stack_b);
		reverse_rotate_n_time(stack_a, 2, STACK_A);
	}
	else
		end_sort_three_a(stack_a, stack_b, y, z);
	return (0);
}
