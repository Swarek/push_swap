/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_which_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:19:51 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/19 19:15:39 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_which_rotation(t_stack **stack_a, int rotation)
{
	if (rotation == ROTATE)
	{
		do_ra(stack_a);
	}
	else
	{
		do_rra(stack_a);
	}
}
