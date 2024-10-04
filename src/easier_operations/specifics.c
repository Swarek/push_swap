/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:15:28 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 16:51:46 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Search the shortest way to rotate to top target
void	rotate_to_top_a(t_stack **stack_a, int target)
{
	int	len;
	int	placement;

	len = stack_length(*stack_a);
	placement = stackfind(*stack_a, target);
	if (placement == -1)
		return ;
	if (placement < len / 2)
		rotate_n_time(stack_a, placement, STACK_A);
	else
		reverse_rotate_n_time(stack_a, len - placement, STACK_A);
}

void	rotate_and_push_b(t_stack **stack_a, t_stack **stack_b, int target)
{
	rotate_to_top_a(stack_a, target);
	do_pb(stack_a, stack_b);
}
