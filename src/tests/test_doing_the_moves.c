// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_doing_the_moves.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/03 22:51:29 by mblanc            #+#    #+#             */
// /*   Updated: 2024/10/03 23:08:35 by mblanc           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// // Test of the doing_the_moves() function

// #include "push_swap.h"

// // Function to create a stack from an array
// t_stack *create_stack(int *values, int size);

// // Function to free the memory of a stack
// void free_stack_memory(t_stack *stack);

// // Test 1: Rotate both stacks
// void test_doing_the_moves_double_rotate()
// {
// 	int values_a[] = {3, 2, 1};
// 	int values_b[] = {6, 5, 4};
// 	t_stack *stack_a = create_stack(values_a, 3);
// 	t_stack *stack_b = create_stack(values_b, 3);
// 	t_cost cost = {0, 0, ROTATE, ROTATE, 1, 1};

// 	ft_printf("\nTEST Doing The Moves Double Rotate:\n");

// 	doing_the_moves(&stack_a, &stack_b, &cost);

// 	// After rotating both stacks, check the new order.
// 	// if (stack_a->value == 2 && stack_b->value == 5)
// 	// 	ft_printf("[PASS] Test Doing The Moves Double Rotate\n");
// 	// else
// 	// 	ft_printf("[FAIL] Test Doing The Moves Double Rotate\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 2: Reverse rotate both stacks
// void test_doing_the_moves_double_reverse_rotate()
// {
// 	int values_a[] = {1, 2, 3};
// 	int values_b[] = {4, 5, 6};
// 	t_stack *stack_a = create_stack(values_a, 3);
// 	t_stack *stack_b = create_stack(values_b, 3);
// 	t_cost cost = {0, 0, REVERSE_ROTATE, REVERSE_ROTATE, 1, 2};

// 	ft_printf("\nTEST Doing The Moves Double Reverse Rotate:\n");
// 	doing_the_moves(&stack_a, &stack_b, &cost);

// 	// After reverse rotating both stacks, check the new order.
// 	// if (stack_a->value == 3 && stack_b->value == 6)
// 	// 	ft_printf("[PASS] Test Doing The Moves Double Reverse Rotate\n");
// 	// else
// 	// 	ft_printf("[FAIL] Test Doing The Moves Double Reverse Rotate\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 3: Rotate stack A only
// void test_doing_the_moves_rotate_a()
// {
// 	int values_a[] = {1, 2, 3};
// 	int values_b[] = {4, 5, 6};
// 	t_stack *stack_a = create_stack(values_a, 3);
// 	t_stack *stack_b = create_stack(values_b, 3);
// 	t_cost cost = {0, 0, ROTATE, 0, 2, 0};

// 	ft_printf("\nTEST Doing The Moves Rotate Stack A:\n");
// 	doing_the_moves(&stack_a, &stack_b, &cost);

// 	// After rotating stack A, check the new order.
// 	// if (stack_a->value == 3 && stack_length(stack_a) == 3)
// 	// 	ft_printf("[PASS] Test Doing The Moves Rotate Stack A\n");
// 	// else
// 	// 	ft_printf("[FAIL] Test Doing The Moves Rotate Stack A\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 4: Reverse rotate stack B only
// void test_doing_the_moves_reverse_rotate_b()
// {
// 	int values_a[] = {1, 2, 3};
// 	int values_b[] = {4, 5, 6};
// 	t_stack *stack_a = create_stack(values_a, 3);
// 	t_stack *stack_b = create_stack(values_b, 3);
// 	t_cost cost = {0, 0, 0, REVERSE_ROTATE, 0, 1};

// 	ft_printf("\nTEST Doing The Moves Reverse Rotate Stack B:\n");
// 	doing_the_moves(&stack_a, &stack_b, &cost);

// 	// After reverse rotating stack B, check the new order.
// 	// if (stack_b->value == 6 && stack_length(stack_b) == 3)
// 	// 	ft_printf("[PASS] Test Doing The Moves Reverse Rotate Stack B\n");
// 	// else
// 	// 	ft_printf("[FAIL] Test Doing The Moves Reverse Rotate Stack B\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// // Test 5: Push element from stack A to stack B
// void test_doing_the_moves_push_a_to_b()
// {
// 	int values_a[] = {1, 2, 3};
// 	int values_b[] = {4, 5, 6};
// 	t_stack *stack_a = create_stack(values_a, 3);
// 	t_stack *stack_b = create_stack(values_b, 3);
// 	t_cost cost = {0, 0, 0, 0, 0, 0};

// 	ft_printf("\nTEST Doing The Moves Push A to B:\n");
// 	doing_the_moves(&stack_a, &stack_b, &cost);

// 	// After pushing from stack A to stack B, check the new size of both stacks.
// 	// if (stack_length(stack_a) == 2 && stack_length(stack_b) == 4)
// 	// 	ft_printf("[PASS] Test Doing The Moves Push A to B\n");
// 	// else
// 	// 	ft_printf("[FAIL] Test Doing The Moves Push A to B\n");

// 	free_stack_memory(stack_a);
// 	free_stack_memory(stack_b);
// }

// int test_doing_the_moves()
// {
// 	test_doing_the_moves_double_rotate();
// 	test_doing_the_moves_double_reverse_rotate();
// 	test_doing_the_moves_rotate_a();
// 	test_doing_the_moves_reverse_rotate_b();
// 	test_doing_the_moves_push_a_to_b();

// 	return 0;
// }