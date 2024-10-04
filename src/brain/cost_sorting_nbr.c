/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sorting_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:40:32 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 05:54:17 by mblanc           ###   ########.fr       */
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

// int	sorted_b(t_stack *stack_b)
// {
// 	int	minimum;
// 	int	actual;

// 	minimum = find_minimum(stack_b);
// 	if (minimum != 1)
// 		return (0);
// 	actual = minimum + 1;
// 	while (stackfind(stack_b, actual) != -1)
// 		actual++;
// 	return (actual);
// }

// // Return the cost saved, calculating the nbr of nbr > the hole
// int	complete_hole(t_stack *stack_b, int nbr)
// {
// 	int	actual;
// 	int	result;

// 	actual = sorted_b(stack_b);
// 	result = 0;
// 	if (++actual == nbr)
// 		while (stackfind(stack_b, ++actual) != -1)
// 			result++;
// 	return (result);
// }

// // Calcul the nbr of empty places between the actual sorted b and the nbr
// // More there is empty, more the futur cost is high because we will have to
// // rotate more next times
// int	nbr_empty_sorted_b_nbr(t_stack *stack_b, int nbr)
// {
// 	int	actual;
// 	int	nbr_empty;

// 	actual = sorted_b(stack_b);
// 	nbr_empty = 0;
// 	while (actual < nbr)
// 	{
// 		if (stackfind(stack_b, actual) == -1)
// 			nbr_empty++;
// 		actual++;
// 	}
// 	return (nbr_empty);
// }

// void	calculating_futur(t_stack *stack_a, t_stack *stack_b, int nbr, t_cost *c)
// {
// 	int	futur;

// 	futur = nbr_empty_sorted_b_nbr(stack_b, nbr);
// 	futur -= complete_hole(stack_b, nbr);
// 	c->cost += futur;
// }

int cost_rotate_to_top_nbr(t_stack *stack, int nbr)
{
	int	pos;
	int	len;

	pos = stackfind(stack, nbr);
	if (pos == -1)
		return (-1);
	len = stack_length(stack);
	if (pos <= len / 2)
		return (pos);
	else
		return (len - pos);
}

int calculate_adjacency_bonus(t_stack *stack_b, int nbr)
{
	int	bonus = 0;
	int	cost_to_bring_nbr_minus_1;
	int	cost_to_bring_nbr_plus_1;

	cost_to_bring_nbr_minus_1 = cost_rotate_to_top_nbr(stack_b, nbr - 1);
	if (cost_to_bring_nbr_minus_1 != -1)
	{
		bonus += (10 - cost_to_bring_nbr_minus_1);
	}
	cost_to_bring_nbr_plus_1 = cost_rotate_to_top_nbr(stack_b, nbr + 1);
	if (cost_to_bring_nbr_plus_1 != -1)
		bonus += (10 - cost_to_bring_nbr_plus_1);
	return (bonus);
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
	//c->cost -= calculate_adjacency_bonus(stack_b, nbr);
	c->nbr = nbr;
}
