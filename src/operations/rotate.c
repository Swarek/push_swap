/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:12:56 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/03 22:57:54 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
int	do_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
	{
		ft_printf("error\n");
		return (0);
	}
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	ft_printf("ra\n");
	return (1);
}

// Shift up all elements of stack b by 1.
int	do_rb(t_stack **stack_b)
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
	ft_printf("rb\n");
	return (1);
}

// ra and rb at the same time.
int	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && (*stack_a) && (*stack_a)->next)
		sim_ra(stack_a);
	if (stack_b && (*stack_b) && (*stack_b)->next)
		sim_rb(stack_b);
	ft_printf("rr\n");
	return (1);
}

// Shift down all elements of stack a by 1.
int	do_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (-1);
	before_last = *stack_a;
	while (before_last->next->next)
		before_last = before_last->next;
	temp = before_last->next;
	before_last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("rra\n");
	return (1);
}

// Shift down all elements of stack b by 1.
int	do_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (-1);
	before_last = *stack_b;
	while (before_last->next->next)
		before_last = before_last->next;
	temp = before_last->next;
	before_last->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("rrb\n");
	return (1);
}
