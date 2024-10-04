/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_best_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:33:06 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 09:14:55 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	evaluate_all_nbrs(t_stack *a, t_stack *b, t_cost *c)
{
	int		i;
	int		len;
	int		value;
	t_cost	*memo;

	len = stack_length(a);
	memo = t_cost_dup(c);
	i = -1;
	while (++i < len)
	{
		value = get_nth_node(a, i)->value;
		if (is_in_lis(value, c->lis, c->lis_length))
			continue ;
		cost_sorting_nbr(a, b, value, memo);
		// ft_printf("Evaluating (Firsts) Number: %d, Cost: %d\n", value, memo->cost);
		if (memo->cost < c->cost)
			*c = *memo;
	}
	ft_safe_free((void **)&memo);
}

// Find the best number in stack_a to push in b. It return a t_cost with all the
// informations for pushing.
void	cost_push_best(t_stack **a, t_stack **b, t_cost *cost)
{
	int		len;

	if (!a || !*a)
		return (NULL);
	len = stack_length(*a);
	if (len <= 1)
		return (ft_safe_free((void **)&cost), NULL);
	cost->cost = INT_MAX;
	evaluate_all_nbrs(*a, *b, cost);
	// if (len > sqrt_int(len) + len / 2 + 10)
	// 	evaluate_lasts_nbrs(*a, *b, cost, sqrt_int(len) + len / 2 + 10);
}
