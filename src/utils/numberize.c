/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:23:00 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/16 02:41:10 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifier avant si certains sont egaux
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
				return (ft_error_msg("Same numbers entered"));
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
