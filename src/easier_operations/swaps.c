/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:39:59 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 03:02:54 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_if_needed_a(t_stack *stack_a)
{
	if (stack_a->value < stack_a->next->value)
		return (do_sa(stack_a), TRUE);
	return (FALSE);
}

int	swap_if_needed_b(t_stack *stack_b)
{
	if (stack_b->value < stack_b->next->value)
		return (do_sb(stack_b), TRUE);
	return (FALSE);
}
