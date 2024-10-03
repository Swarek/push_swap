/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sorting_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:40:32 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/25 15:39:17 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation_b_for_insertion_nbr(t_stack *stack_b, t_cost *c, int nbr)
{
	int	place;
	int	len;

	place = find_insert_position(stack_b, nbr);
	len = stack_length(stack_b);
	if (place <= len / 2)
	{
		c->b_rotations = place;
		c->doing_what_b = ROTATE;
	}
	else
	{
		c->b_rotations = len - place;
		c->doing_what_b = REVERSE_ROTATE;
	}
}

static void	rotation_a_for_nbr_to_top(t_stack *stack_a, int nbr, t_cost *c)
{
	int	place;
	int	len;

	place = stackfind(stack_a, nbr);
	len = stack_length(stack_a);
	if (place < len / 2 + 1)
	{
		c->doing_what_a = ROTATE;
		c->a_rotations = place;
	}
	else
	{
		c->doing_what_a = REVERSE_ROTATE;
		c->a_rotations = len - place;
	}
}

// The goal is to find the best cost to push nbr in stack_b.
void	cost_sorting_nbr(t_stack *stack_a, t_stack *stack_b, int nbr, t_cost *c)
{
	rotation_a_for_nbr_to_top(stack_a, nbr, c);
	rotation_b_for_insertion_nbr(stack_b, c, nbr);
	if (c->doing_what_a == c->doing_what_b)
	{
		if (c->a_rotations > c->b_rotations)
			c->cost = c->a_rotations;
		else
			c->cost = c->b_rotations;
	}
	else
		c->cost = c->a_rotations + c->b_rotations;
	c->nbr = nbr;
}
