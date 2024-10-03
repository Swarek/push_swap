/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:15:28 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/23 19:30:01 by mblanc           ###   ########.fr       */
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

void	rotate_to_top_b(t_stack **stack_b, int target)
{
	int	len;
	int	placement;

	len = stack_length(*stack_b);
	placement = stackfind(*stack_b, target);
	if (placement == -1)
		return ;
	if (placement < len / 2)
		rotate_n_time(stack_b, placement, STACK_B);
	else
		reverse_rotate_n_time(stack_b, len - placement, STACK_B);
}
