/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:23:45 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 09:05:07 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doing_the_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (!cost)
		return ;
	if (cost->doing_what_a == ROTATE && cost->doing_what_b == ROTATE)
		double_rotate(stack_a, stack_b, cost);
	else if (cost->doing_what_a == REVERSE_ROTATE
		&& cost->doing_what_b == REVERSE_ROTATE)
		rev_double_rotate(stack_a, stack_b, cost);
	else
	{
		//ft_printf("PASSSAGEE\n");
		while (cost->a_rotations-- > 0)
			do_which_rotation(stack_a, cost->doing_what_a, 0);
		while (cost->b_rotations-- > 0)
			do_which_rotation(stack_b, cost->doing_what_b, 1);
	}
	do_pb(stack_a, stack_b);
}

void	smart_moves(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	cost_push_best(stack_a, stack_b, cost);
	doing_the_moves(stack_a, stack_b, cost);
}
