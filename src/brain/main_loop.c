/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:14:55 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 09:05:21 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_stack(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	min_sorted_from_high(t_stack *stack)
{
	int	max;
	int	current;

	max = find_maximum(stack);
	current = max;
	while (is_in_stack(stack, current))
		current = current - 1;
	return (current + 1);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_a;
	int	max_b;
	int	min_a;

	while (*stack_b)
	{
		max_a = find_maximum(*stack_a);
		min_a = find_minimum(*stack_a);
		max_b = find_maximum(*stack_b);
		if (max_b > max_a)
			rotate_to_top_a(stack_a, min_a);
		else
			rotate_to_top_a(stack_a, min_sorted_from_high(*stack_a));
		while ((*stack_b)->value != max_b)
		{
			if (stackfind(*stack_b, max_b) <= stack_length(*stack_b) / 2)
				do_rb(stack_b);
			else
				do_rrb(stack_b);
		}
		do_pa(stack_a, stack_b);
	}
}

int	main_loop(t_stack **stack_a, t_stack **stack_b)
{
	t_cost		*cost;

	cost = ft_safe_malloc(sizeof(t_cost));
	cost->lis = find_lis(*stack_a, &(cost->lis_length));
	*stack_b = NULL;
	while (stack_length(*stack_a) > cost->lis_length)
	{
		smart_moves(stack_a, stack_b, cost);
	}
	push_back_to_a(stack_a, stack_b);
	clear_stack(stack_b);
	return (0);
}
