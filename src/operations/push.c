/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:12:55 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/23 16:57:01 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a
int	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return (0);
	temp = (*stack_b)->next;
	stackadd_front(stack_a, *stack_b);
	*stack_b = temp;
	ft_printf("pa\n");
	return (1);
}

// Take the first element at the top of a and put it at the top of b.
int	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return (0);
	temp = (*stack_a)->next;
	stackadd_front(stack_b, *stack_a);
	*stack_a = temp;
	ft_printf("pb\n");
	return (1);
}
