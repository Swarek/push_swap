/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:12:58 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/23 16:59:33 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
int	sim_sa(t_stack *stack_a)
{
	t_stack	*copy_a;
	int		temp;

	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	copy_a = stack_a->next;
	temp = stack_a->value;
	stack_a->value = copy_a->value;
	copy_a->value = temp;
	return (1);
}

// Swap the first 2 elements at the top of stack b.
int	sim_sb(t_stack *stack_b)
{
	t_stack	*copy_b;
	int		temp;

	if (stack_b == NULL || stack_b->next == NULL)
		return (0);
	copy_b = stack_b->next;
	temp = stack_b->value;
	stack_b->value = copy_b->value;
	copy_b->value = temp;
	return (1);
}

int	sim_ss(t_stack *stack_a, t_stack *stack_b)
{
	sim_sa(stack_a);
	sim_sb(stack_b);
	return (1);
}
