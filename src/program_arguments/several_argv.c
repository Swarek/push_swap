/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:27 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/10 21:46:28 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_duplicate(t_stack *stack)
{
	t_stack	*compared_stack;
	t_stack	*head;

	head = stack;
	while (stack)
	{
		compared_stack = head;
		while (compared_stack)
		{
			if (compared_stack->value == stack->value
				&& compared_stack != stack)
				return (1);
			compared_stack = compared_stack->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_stack	*parse_arguments(char **args)
{
	t_stack	*head;
	int		i;

	i = -1;
	if (!args[0])
		return (NULL);
	while (args[++i])
		if (validate_no_multiple_spaces(args[i]) == -1)
			return (NULL);
	if (check_all_number_limits(args) == -1)
		return (NULL);
	head = strings_to_stack(args);
	if (verif_duplicate(head))
		return (ft_error_msg(""), clear_stack(&head), NULL);
	return (head);
}
