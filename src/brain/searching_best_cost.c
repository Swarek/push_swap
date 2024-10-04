/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_best_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:33:06 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 03:20:32 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	evaluate_firsts_nbrs(t_stack *a, t_stack *b, t_cost *c, int howmuch)
{
	int		i;
	int		len;
	int		value;
	t_cost	*memo;

	len = stack_length(a);
	memo = ft_safe_malloc(sizeof(t_cost));
	if (len < howmuch)
		howmuch = len;
	i = 0;
	while (i < howmuch)
	{
		value = get_nth_node(a, i)->value;
		cost_sorting_nbr(a, b, value, memo);
		// ft_printf("Evaluating (Firsts) Number: %d, Cost: %d\n", value, memo->cost);
		if (memo->cost < c->cost)
			*c = *memo;
		i++;
	}
	ft_safe_free((void **)&memo);
}

static void	evaluate_lasts_nbrs(t_stack *a, t_stack *b, t_cost *c, int howmuch)
{
	int		i;
	int		len;
	t_cost	*memo;

	len = stack_length(a);
	memo = ft_safe_malloc(sizeof(t_cost));
	if (len < howmuch)
	{
		ft_safe_free((void **)&memo);
		return ;
	}
	i = len - howmuch;
	while (i < len)
	{
		int value = get_nth_node(a, i)->value;
		cost_sorting_nbr(a, b, value, memo);
		//ft_printf("Evaluating (Lasts) Number: %d, Cost: %d\n", value, memo->cost);
		if (memo->cost < c->cost)
			*c = *memo;
		i++;
	}
	ft_safe_free((void **)&memo);
}

// Find the best number in stack_a to push in b. It return a t_cost with all the
// informations for pushing.
t_cost	*cost_push_best(t_stack **a, t_stack **b)
{
	t_cost	*cost;
	int		len;

	if (!a || !*a)
		return (NULL);
	cost = ft_safe_malloc(sizeof(t_cost));
	if (stack_length(*a) <= 1)
		return (ft_safe_free((void **)&cost), NULL);
	cost->cost = INT_MAX;
	len = stack_length(*a);
	evaluate_firsts_nbrs(*a, *b, cost, sqrt_int(len) + len / 10 + 10);
	if (len > sqrt_int(len) + len / 10 + 10)
		evaluate_lasts_nbrs(*a, *b, cost, sqrt_int(len) + len / 10 + 10);
	return (cost);
}
