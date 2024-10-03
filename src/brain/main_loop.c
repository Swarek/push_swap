/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:14:55 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 19:03:24 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	while (*stack_b)
	{
		max = find_maximum(*stack_b);
		while ((*stack_b)->value != max)
		{
			if (stackfind(*stack_b, max) <= stack_length(*stack_b) / 2)
				do_rb(stack_b);
			else
				do_rrb(stack_b);
		}
		do_pa(stack_a, stack_b);
	}
}

void	update_highest_tryable(t_stack **stack_b, t_search *search)
{
	int	current_length;

	if (*stack_b)
	{
		current_length = stack_length(*stack_b);
		if (current_length / 3 < search->highest_tryable
			&& search->highest_tryable <= 500)
			search->highest_tryable += 10;
	}
}

int	main_loop(t_stack **stack_a, t_stack **stack_b)
{
	t_search	*find;

	find = initialize_search();
	*stack_b = NULL;
	while (*stack_a)
	{
		update_search(find, find->range, find->approx, find->highest_tryable);
		smart_moves(stack_a, stack_b);
		update_highest_tryable(stack_b, find);
		if (!stack_a || !(*stack_a) || !(*stack_a)->next)
			break ;
	}
	push_back_to_a(stack_a, stack_b);
	//free_in_range(find->nbrs_list);
	clear_stack(stack_b);
	ft_safe_free((void **)&find);
	return (0);
}
