// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_smart_moves.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/03 22:47:27 by mblanc            #+#    #+#             */
// /*   Updated: 2024/10/04 06:29:05 by mblanc           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// // Test of the smart_moves() function

// #include "push_swap.h"

// Function to check if the stack is sorted
// int is_sorted(t_stack *stack)
// {
// 	if (!stack)
// 		return (1);
// 	while (stack->next)
// 	{
// 		if (stack->value > stack->next->value)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

// // Test 1: Movement with minimal cost
// void test_smart_moves_simple_case()
// {
// 	int values_a[] = {4, 3, 1, 2};
// 	int values_b[] = {5, 6};
// 	t_stack *stack_a = create_stack(values_a, 4);
// 	t_stack *stack_b = create_stack(values_b, 2);

// 	ft_printf("\nTEST Smart Moves Simple Case:\n");

// 	smart_moves(&stack_a, &stack_b);

// 	// After the moves, stack b should contain one more element.
// 	if (stack_length(stack_b) == 3)
// 		ft_printf("[PASS] Test Smart Moves Simple Case\n");
// 	else
// 		ft_printf("[FAIL] Test Smart Moves Simple Case\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 2: Stack A already sorted, no movement needed
// void test_smart_moves_already_sorted()
// {
// 	int values_a[] = {1, 2, 3, 4};
// 	int values_b[] = {5, 6};
// 	t_stack *stack_a = create_stack(values_a, 4);
// 	t_stack *stack_b = create_stack(values_b, 2);

// 	ft_printf("\nTEST Smart Moves Already Sorted:\n");

// 	smart_moves(&stack_a, &stack_b);

// 	// Check that stack A is still sorted after calling smart_moves().
// 	if (is_sorted(stack_a))
// 		ft_printf("[PASS] Test Smart Moves Already Sorted\n");
// 	else
// 		ft_printf("[FAIL] Test Smart Moves Already Sorted\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 3: Large stack with complex movement
// void test_smart_moves_large_stack()
// {
// 	int values_a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
// 	int values_b[] = {11, 12, 13};
// 	t_stack *stack_a = create_stack(values_a, 10);
// 	t_stack *stack_b = create_stack(values_b, 3);

// 	ft_printf("\nTEST Smart Moves Large Stack:\n");

// 	smart_moves(&stack_a, &stack_b);

// 	// Check that stack B has one more element.
// 	if (stack_length(stack_b) == 4)
// 		ft_printf("[PASS] Test Smart Moves Large Stack\n");
// 	else
// 		ft_printf("[FAIL] Test Smart Moves Large Stack\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 4: Stack A with a single element
// void test_smart_moves_single_element()
// {
// 	int values_a[] = {1};
// 	int values_b[] = {2, 3, 4};
// 	t_stack *stack_a = create_stack(values_a, 1);
// 	t_stack *stack_b = create_stack(values_b, 3);

// 	ft_printf("\nTEST Smart Moves Single Element:\n");

// 	smart_moves(&stack_a, &stack_b);

// 	// Check that stack A is empty after pushing the element to B.
// 	if (stack_a == NULL && stack_length(stack_b) == 4)
// 		ft_printf("[PASS] Test Smart Moves Single Element\n");
// 	else
// 		ft_printf("[FAIL] Test Smart Moves Single Element\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 5: Empty stack A
// void test_smart_moves_empty_a()
// {
// 	int values_a[] = {};
// 	int values_b[] = {1, 2, 3};
// 	t_stack *stack_a = create_stack(values_a, 0);
// 	t_stack *stack_b = create_stack(values_b, 3);

// 	ft_printf("\nTEST Smart Moves Empty A:\n");

// 	smart_moves(&stack_a, &stack_b);

// 	// No modification should occur, as A is empty.
// 	if (stack_length(stack_b) == 3)
// 		ft_printf("[PASS] Test Smart Moves Empty A\n");
// 	else
// 		ft_printf("[FAIL] Test Smart Moves Empty A\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// int test_smart_moves()
// {
// 	test_smart_moves_simple_case();
// 	test_smart_moves_already_sorted();
// 	test_smart_moves_large_stack();
// 	test_smart_moves_single_element();
// 	test_smart_moves_empty_a();

// 	return 0;
// }