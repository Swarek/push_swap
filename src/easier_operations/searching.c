/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:42:43 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/16 02:42:25 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_stack *stack)
{
	int	minimum;

	if (!stack)
		return (0);
	minimum = stack->value;
	while (stack)
	{
		if (stack->value < minimum)
			minimum = stack->value;
		stack = stack->next;
	}
	return (minimum);
}

int	find_maximum(t_stack *stack)
{
	int	maximum;

	if (!stack)
		return (0);
	maximum = stack->value;
	while (stack)
	{
		if (stack->value > maximum)
			maximum = stack->value;
		stack = stack->next;
	}
	return (maximum);
}
