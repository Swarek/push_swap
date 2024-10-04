/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_which_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:19:51 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 03:18:32 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_which_rotation(t_stack **stack, int rotation, int which_stack)
{
	if (which_stack == 0)
	{
		if (rotation == ROTATE)
			do_ra(stack);
		else
			do_rra(stack);
	}
	else
	{
		if (rotation == ROTATE)
			do_rb(stack);
		else
			do_rrb(stack);
	}
}
