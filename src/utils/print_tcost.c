/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tcost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 00:23:20 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 00:23:30 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_t_cost(t_cost *cost)
{
	if (!cost)
		return ;
	ft_printf("Cost Details:\n");
	ft_printf("Cost: %d\n", cost->cost);
	ft_printf("Number: %d\n", cost->nbr);
	ft_printf("Doing What A: %d\n", cost->doing_what_a);
	ft_printf("Doing What B: %d\n", cost->doing_what_b);
	ft_printf("A Rotations: %d\n", cost->a_rotations);
	ft_printf("B Rotations: %d\n", cost->b_rotations);
}
