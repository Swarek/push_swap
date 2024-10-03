/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:07 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/03 23:09:07 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----
void	print_tstack(t_stack *lst)
{
	while (lst != NULL)
	{
		ft_printf("%d ", lst->value);
		lst = lst->next;
	}
}

// void	test(t_stack **stack_a, t_stack **stack_b)
// {
// 	// t_search	*search;
// 	// t_cost		*cost;

// 	test_best_ranges(stack_a);
// 	// //cost = calculate_cost_to_top(*stack_a, 13);
// 	// //free(cost);
// }

void	safe_all(t_stack **stack_a, t_stack **stack_b)
{
	print_tstack(*stack_a);
	if (stack_a && *stack_a)
	{
		ft_printf("Clearing stack_a\n");
		clear_stack(stack_a);
		*stack_a = NULL;
	}
	else
	{
		ft_printf("Warning: stack_a is not initialized or already empty.\n");
	}
	if (stack_b && *stack_b)
	{
		ft_printf("Clearing stack_b\n");
		clear_stack(stack_b);
		*stack_b = NULL;
	}
	else
	{
		ft_printf("Warning: stack_b is not initialized or already empty.\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_error_msg("You need at least 1 argument"));
	else if (argc == 2)
		stack_a = parse_string_argument(argv[1]);
	else
		stack_a = parse_arguments(&argv[1]);
	len = stack_length(stack_a);
	numberize_stack_numbers(stack_a);
	stack_b = NULL;
	main_loop(&stack_a, &stack_b);
	return (safe_all(&stack_a, &stack_b), 0);
	//main_test_cost_sorting_nbr();
	//test_doing_the_moves();
}

// ft_printf("HELLO\n\n\n\n\Voici stack_aaaaa : ");
// 	print_tstack(stack_a);