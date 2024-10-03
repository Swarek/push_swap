/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:55:46 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/25 14:50:41 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nbr_lower_closer(t_stack *stack, int nbr)
{
	int		lower_closer;

	if (!stack->next)
		return (-1);
	lower_closer = -1;
	while (stack)
	{
		if (stack->value < nbr && stack->value > lower_closer)
			lower_closer = stack->value;
		stack = stack->next;
	}
	return (lower_closer);
}

int	find_insert_position(t_stack *stack_b, int nbr)
{
	int		minimum;
	int		maximum;
	int		lower_closer;
	int		cost;

	if (!stack_b)
		return (0);
	minimum = find_minimum(stack_b);
	maximum = find_maximum(stack_b);
	if (nbr > maximum)
		return (stackfind(stack_b, maximum));
	else if (nbr > minimum)
	{
		lower_closer = find_nbr_lower_closer(stack_b, nbr);
		if (lower_closer != -2)
			return (stackfind(stack_b, lower_closer));
		else
			return (stackfind(stack_b, maximum));
	}
	else
		return (stackfind(stack_b, minimum));
}
