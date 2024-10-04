/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:33:06 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 13:42:06 by mblanc           ###   ########.fr       */
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
	if (nbr < minimum)
		return (stackfind(stack_b, maximum));
	else if (nbr < maximum)
	{
		lower_closer = find_nbr_lower_closer(stack_b, nbr);
		if (lower_closer != -2)
			return (stackfind(stack_b, lower_closer));
		else
			return (stackfind(stack_b, minimum));
	}
	else if (nbr > maximum)
	{
		return (stackfind(stack_b, maximum));
	}
}

// Find the best number in stack_a to push in b. It return a t_cost with all the
// informations for pushing.
static void	cost_push_best(t_stack *a, t_stack *b, t_cost *c)
{
	int		i;
	int		len;
	int		value;
	t_cost	*memo;

	if (!a)
		return (NULL);
	len = stack_length(a);
	if (len <= 1)
		return (ft_safe_free((void **)&c), NULL);
	c->cost = INT_MAX;
	memo = t_cost_dup(c);
	i = -1;
	while (++i < len)
	{
		value = get_nth_node(a, i)->value;
		// if (is_in_lis(value, c->lis, c->lis_length))
		// 	continue ;
		cost_sorting_nbr(a, b, value, memo);
		if (memo->cost < c->cost)
			*c = *memo;
	}
	ft_safe_free((void **)&memo);
}

void	smart_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (!cost)
		return ;
	cost_push_best(*stack_a, *stack_b, cost);
	if (cost->doing_what_a == cost->doing_what_b)
	{
		same_doing_what(stack_a, stack_b, cost);
		return ;
	}
	while (cost->a_rotations-- > 0)
	{
		if (cost->doing_what_a == ROTATE)
			do_ra(stack_a);
		else
			do_rra(stack_a);
	}
	while (cost->b_rotations-- > 0)
	{
		if (cost->doing_what_b == ROTATE)
			do_rb(stack_b);
		else
			do_rrb(stack_b);
	}
	do_pb(stack_a, stack_b);
}
