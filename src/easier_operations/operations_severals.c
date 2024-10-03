/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_severals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:03:32 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/16 02:44:22 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n_time(t_stack **stack, int n, int which_stack)
{
	if (which_stack == STACK_A)
		while (n-- > 0)
			do_ra(stack);
	else if (which_stack == STACK_B)
		while (n-- > 0)
			do_rb(stack);
}

void	reverse_rotate_n_time(t_stack **stack, int n, int which_stack)
{
	if (which_stack == STACK_A)
		while (n-- > 0)
			do_rra(stack);
	else if (which_stack == STACK_B)
		while (n-- > 0)
			do_rrb(stack);
}
