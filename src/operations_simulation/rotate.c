/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:12:56 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/23 16:58:57 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
int	sim_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
	{
		ft_printf("error\n");
		return (-1);
	}
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	return (1);
}

// Shift up all elements of stack b by 1.
int	sim_rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	return (1);
}

// ra and rb at the same time.
int	sim_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && (*stack_a) && (*stack_a)->next)
		do_ra(stack_a);
	if (stack_b && (*stack_b) && (*stack_b)->next)
		do_rb(stack_b);
	return (1);
}

// Shift down all elements of stack a by 1.
int	sim_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	before_last = *stack_a;
	while (before_last->next->next)
		before_last = before_last->next;
	temp = before_last->next;
	before_last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	return (1);
}

// Shift down all elements of stack b by 1.
int	sim_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	before_last = *stack_b;
	while (before_last->next->next)
		before_last = before_last->next;
	temp = before_last->next;
	before_last->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	return (1);
}
