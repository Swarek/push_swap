/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:34:18 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 16:58:55 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_case_1(t_stack **stack_a, int a, int b, int c)
{
	if (a > b && b > c)
	{
		do_sa(*stack_a);
		do_rra(stack_a);
	}
	else if (a > c && c > b)
		do_ra(stack_a);
	else if (b > a && b > c)
	{
		do_sa(*stack_a);
		do_ra(stack_a);
	}
}

void	sort_three_case_2(t_stack **stack_a, int a, int b, int c)
{
	if (b > c && c > a)
		do_rra(stack_a);
	else if (a > b && b < c)
		do_sa(*stack_a);
	else if (a < b && b > c && c > a)
		do_rra(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	sort_three_case_1(stack_a, a, b, c);
	sort_three_case_2(stack_a, a, b, c);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	rotate_and_push_b(stack_a, stack_b, find_minimum(*stack_a));
	sort_three(stack_a);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}

int	sort_small_nbrs(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
	{
		rotate_and_push_b(stack_a, stack_b, find_minimum(*stack_a));
		rotate_and_push_b(stack_a, stack_b, find_minimum(*stack_a));
		sort_three(stack_a);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
	}
	return (1);
}
