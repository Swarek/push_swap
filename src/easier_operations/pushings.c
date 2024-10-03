/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:14:17 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/10 21:48:41 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_push_a(t_stack **stack_a, t_stack **stack_b, int target)
{
	rotate_to_top_b(stack_b, target);
	do_pa(stack_a, stack_b);
}

void	rotate_and_push_b(t_stack **stack_a, t_stack **stack_b, int target)
{
	rotate_to_top_a(stack_a, target);
	do_pb(stack_a, stack_b);
}
