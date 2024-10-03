/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:19:54 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/03 23:08:08 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Will do rr since they both need to rotate, then ra or rb for the rest
void	double_rotate(t_stack **a, t_stack **b, t_cost *cost)
{
	int	both;

	if (cost->a_rotations < cost->b_rotations)
		both = cost->a_rotations;
	else
		both = cost->b_rotations;
	while (both-- > 0)
	{
		cost->a_rotations--;
		cost->b_rotations--;
		do_rr(a, b);
	}
	while (cost->a_rotations-- > 0)
		do_ra(a);
	while (cost->b_rotations-- > 0)
		do_rb(b);
}

// Will do rrr since they both need to reve rotate, then rra or rrb for the rest
void	rev_double_rotate(t_stack **a, t_stack **b, t_cost *cost)
{
	int	both;

	if (!cost)
		return ;
	if (cost->a_rotations < cost->b_rotations)
		both = cost->a_rotations;
	else
		both = cost->b_rotations;
	while (both > 0)
	{
		do_rrr(a, b);
		both--;
	}
	while (cost->a_rotations > cost->b_rotations)
	{
		do_rra(a);
		cost->a_rotations--;
	}
	while (cost->b_rotations > cost->a_rotations)
	{
		do_rrb(b);
		cost->b_rotations--;
	}
}
