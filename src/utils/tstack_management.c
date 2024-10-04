/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstack_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:43:15 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 14:21:12 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *lst)
{
	int		count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	stackfind(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

t_stack	*get_nth_node(t_stack *stack, int n)
{
	if (n < 0)
		return (NULL);
	while (n-- > 0 && stack != NULL)
	{
		if (stack->next == NULL)
			return (NULL);
		stack = stack->next;
	}
	return (stack);
}

t_stack	*stackdup(t_stack *lst)
{
	t_stack	*new_list;
	t_stack	*temp;
	t_stack	*new_node;

	if (!lst)
		return (NULL);
	new_list = stacknew(lst->value);
	if (!new_list)
		return (NULL);
	temp = new_list;
	lst = lst->next;
	while (lst)
	{
		new_node = stacknew(lst->value);
		if (!new_node)
		{
			clear_stack(&new_list);
			return (NULL);
		}
		temp->next = new_node;
		temp = temp->next;
		lst = lst->next;
	}
	return (new_list);
}
