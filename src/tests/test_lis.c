/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:04:19 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 06:40:12 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test_find_lis.c

#include "push_swap.h"

// Crée un nouveau nœud de pile
static t_stack	*create_node(int value)
{
	t_stack *new;

	new = ft_safe_malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}


// Libère la mémoire de la pile
static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
// Crée une pile à partir des arguments de la ligne de commande
static t_stack	*create_stack(int argc, char **argv)
{
	t_stack *stack = NULL;
	t_stack *new;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		new = create_node(ft_atoi(argv[i]));
		if (!new)
		{
			while (stack)
			{
				t_stack *tmp = stack;
				stack = stack->next;
				free(tmp);
			}
			return (NULL);
		}
		new->next = stack;
		stack = new;
		i--;
	}
	return (stack);
}

// Affiche la LIS
void	print_lis(int *lis, int lis_length)
{
	int i = 0;
	while (i < lis_length)
	{
		ft_printf("%d ", lis[i]);
		i++;
	}
	ft_printf("\n");
}


// Programme principal pour tester find_lis
int	test_lis(int argc, char **argv)
{
	t_stack *stack_a;
	int		*lis;
	int		lis_length;

	ft_printf("\n\n\n");
	if (argc < 2)
		return (0);
	stack_a = create_stack(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error: Could not create stack\n");
		return (1);
	}
	lis = find_lis(stack_a, &lis_length);
	if (!lis)
	{
		ft_printf("Error: Could not find LIS\n");
		free_stack(stack_a);
		return (1);
	}
	print_lis(lis, lis_length);
	ft_safe_free((void **)&lis);
	free_stack(stack_a);
	return (0);
}
