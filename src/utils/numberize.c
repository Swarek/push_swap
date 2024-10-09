/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:34:44 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 18:34:49 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verify if there are duplicate numbers in the stack
static int	has_duplicate_numbers(t_stack *stack_a)
{
	t_stack	*compared_stack;
	t_stack	*head;

	head = stack_a;
	while (stack_a)
	{
		compared_stack = head;
		while (compared_stack)
		{	
			if (compared_stack->value == stack_a->value
				&& compared_stack != stack_a)
				return (ft_error_msg(""));
			compared_stack = compared_stack->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

static int	count_lower_numbers(t_stack *stack_a, int the_compared)
{
	int		nbr;

	nbr = 0;
	while (stack_a)
	{
		if (stack_a->value < the_compared)
			nbr++;
		stack_a = stack_a->next;
	}
	return (nbr);
}

void	numberize_stack_numbers(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*copy;

	copy = stackdup(stack_a);
	current = stack_a;
	while (current)
	{
		current->value = count_lower_numbers(copy, current->value) + 1;
		current = current->next;
	}
	clear_stack(&copy);
}
