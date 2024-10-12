/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:47:50 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/12 15:14:00 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_for_checker(void)
{
	char	*line;
	char	**operations;
	int		i;

	operations = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		operations = ft_realloc(operations, (i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		if (!operations)
			exit(EXIT_FAILURE);
		operations[i] = line;
		i++;
		operations[i] = NULL;
	}
	return (operations);
}

int	is_operation(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0
		|| ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "ra\n") == 0
		|| ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rrr\n") == 0)
		return (TRUE);
	return (FALSE);
}

int	verif_only_operations(char **operations)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		if (!is_operation(operations[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	do_operation(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		do_sa(*stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_sb(*stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		do_ss(*stack_a, *stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		do_pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		do_ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_rrr(stack_a, stack_b);
}

int	checker(t_stack **stack_a)
{
	t_stack	*stack_b;
	char	**operations;
	int		i;

	stack_b = NULL;
	operations = parse_for_checker();
	if (verif_only_operations(operations) == FALSE)
		return (ft_error_msg(""), safe_free_all_strings(&operations), FALSE);
	i = 0;
	while (operations[i])
	{
		do_operation(operations[i], stack_a, &stack_b);
		i++;
	}
	if (is_sorted(*stack_a) && !stack_b)
		return (ft_printf("OK\n"), safe_free_all_strings(&operations), TRUE);
	return (ft_printf("KO\n"), safe_free_all_strings(&operations), FALSE);
}
