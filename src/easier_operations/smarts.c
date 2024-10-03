/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smarts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:56:25 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 02:34:20 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **stack_a, t_stack **stack_b, int which)
{
	int	minimum;

	if (which == STACK_A)
	{
		minimum = find_minimum(*stack_b);
		rotate_and_push_a(stack_a, stack_b, minimum);
	}
	else if (which == STACK_B)
	{
		minimum = find_minimum(*stack_a);
		rotate_and_push_b(stack_a, stack_b, minimum);
	}
}

void	push_max(t_stack **stack_a, t_stack **stack_b, int which)
{
	int	maximum;

	if (which == STACK_A)
	{
		maximum = find_maximum(*stack_b);
		rotate_and_push_a(stack_a, stack_b, maximum);
	}
	else if (which == STACK_B)
	{
		maximum = find_maximum(*stack_a);
		rotate_and_push_b(stack_a, stack_b, maximum);
	}
}

// Push dans b du plus petit au plus grand de la range
void	push_range_to_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	tofind;

	while (min < max)
	{
		tofind = stackfind(*stack_a, min);
		if (tofind != -1)
			rotate_and_push_b(stack_a, stack_b, tofind);
	}
}

// Push dans a du plus petit au plus grand de la range
void	push_range_to_a(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	tofind;

	while (min < max)
	{
		tofind = stackfind(*stack_b, min);
		if (tofind != -1)
			rotate_and_push_a(stack_a, stack_b, tofind);
	}
}
