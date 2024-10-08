/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:00:05 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/03 22:58:29 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && (*stack_a) && (*stack_a)->next)
		sim_rra(stack_a);
	if (stack_b && (*stack_b) && (*stack_b)->next)
		sim_rrb(stack_b);
	ft_printf("rrr\n");
	return (1);
}
