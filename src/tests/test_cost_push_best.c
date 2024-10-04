// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_cost_push_best.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/25 15:54:42 by mblanc            #+#    #+#             */
// /*   Updated: 2024/10/03 22:36:53 by mblanc           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// // Test 1: Piles Simples avec Quelques Éléments
// void test_cost_push_best_simple()
// {
//     int		values_a[] = {2, 1, 3};
//     int		values_b[] = {};
//     t_stack	*stack_a;
//     t_stack	*stack_b;

// 	stack_a = create_stack(values_a, 3);
// 	stack_b = create_stack(values_b, 0);
// 	ft_printf("\nTEST 1 : \n");
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 0;          // Coût attendu
//     expected->nbr = 2;           // Nombre attendu
//     expected->doing_what_a = ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 0;
//     expected->b_rotations = 0;
    
// 	// Problem en dessous
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     // Assurez-vous que actual n'est pas NULL
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Simple");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Simple: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 2: Pile A Déjà Triée
// void test_cost_push_best_sorted_a()
// {
//     int values_a[] = {1, 2, 3, 4, 5};
//     int values_b[] = {6, 7, 8};
//     t_stack *stack_a = create_stack(values_a, 5);
//     t_stack *stack_b = create_stack(values_b, 3);
    
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
// 	ft_printf("\nTEST 2 : \n");
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 0;          // Coût attendu (meilleur coût possible)
//     expected->nbr = 1;           // Nombre attendu (le premier pour minimiser les rotations)
//     expected->doing_what_a = ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 0;
//     expected->b_rotations = 0;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Sorted A");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Sorted A: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 3: Pile B Non Vide avec Besoins de Rotations
// void test_cost_push_best_with_rotations()
// {
//     int values_a[] = {4, 3, 2, 1};
//     int values_b[] = {5, 6};
//     t_stack *stack_a = create_stack(values_a, 4);
//     t_stack *stack_b = create_stack(values_b, 2);
    
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
// 	ft_printf("\nTEST 3 : \n");
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 0;          // Coût attendu
//     expected->nbr = 4;           // Nombre attendu
//     expected->doing_what_a = ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 0;
//     expected->b_rotations = 0;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best With Rotations");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best With Rotations: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 4: Pile A avec un Seul Élément
// void test_cost_push_best_single_element()
// {
//     int values_a[] = {1, 5};
//     int values_b[] = {3, 4, 2};
//     t_stack *stack_a = create_stack(values_a, 2);
//     t_stack *stack_b = create_stack(values_b, 3);
    
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
// 	ft_printf("\nTEST 4 : \n");
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 0;          // Coût attendu
//     expected->nbr = 1;           // Nombre attendu
//     expected->doing_what_a = ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 0;
//     expected->b_rotations = 0;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Single Element");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Single Element: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 5: Pile A Vide
// void test_cost_push_best_empty_a()
// {
//     int values_a[] = {};
//     int values_b[] = {1, 2, 3};
//     t_stack *stack_a = create_stack(values_a, 0);
//     t_stack *stack_b = create_stack(values_b, 3);
    
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
// 	ft_printf("\nTEST 5 : \n");
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = INT_MAX;    // Coût attendu (aucun élément à pousser)
//     expected->nbr = 0;           // Valeur par défaut
//     expected->doing_what_a = ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 0;
//     expected->b_rotations = 0;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Empty A");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Empty A: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 6: Grandes Piles pour Tester Performance
// void test_cost_push_best_large_stacks()
// {
//     // Crée une grande pile a
//     int size_a = 100;
//     int *values_a = malloc(sizeof(int) * size_a);
//     for(int i = 0; i < size_a; i++)
//         values_a[i] = size_a - i; // [100, 99, ..., 1]
    
//     // Crée une grande pile b
//     int size_b = 50;
//     int *values_b = malloc(sizeof(int) * size_b);
// 	ft_printf("\nTEST 6 : \n");
//     for(int i = 0; i < size_b; i++)
//         values_b[i] = size_b + i + 1; // [51, 52, ..., 100]
    
//     t_stack *stack_a = create_stack(values_a, size_a);
//     t_stack *stack_b = create_stack(values_b, size_b);
    
//     // Attendu: le nombre 1 dans a est en dernière position
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 50 + 49; // a_rotations=50 (REVERSE_ROTATE), b_rotations=49 (REVERSE_ROTATE)
//     expected->nbr = 1;
//     expected->doing_what_a = REVERSE_ROTATE;
//     expected->doing_what_b = REVERSE_ROTATE;
//     expected->a_rotations = 50;
//     expected->b_rotations = 49;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Large Stacks");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Large Stacks: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free(values_a);
//     free(values_b);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// // Test 7: Pile B avec Un Seul Élément
// void test_cost_push_best_single_element_b()
// {
//     int values_a[] = {3, 2, 1};
//     int values_b[] = {4};
//     t_stack *stack_a = create_stack(values_a, 3);
//     t_stack *stack_b = create_stack(values_b, 1);
    
//     t_cost *expected = ft_safe_malloc(sizeof(t_cost));
// 	ft_printf("\nTEST 7 : \n");
//     if (!expected)
//     {
//         perror("malloc");
//         exit(EXIT_FAILURE);
//     }
//     expected->cost = 1;          // Coût attendu
//     expected->nbr = 1;           // Nombre attendu
//     expected->doing_what_a = REVERSE_ROTATE;
//     expected->doing_what_b = ROTATE;
//     expected->a_rotations = 2;
//     expected->b_rotations = 1;
    
//     t_cost *actual = cost_push_best(&stack_a, &stack_b);
    
//     if (actual)
//     {
//         assert_cost(*expected, *actual, "Test Cost Push Best Single Element B");
//         ft_safe_free((void **)&actual);
//     }
//     else
//     {
//         printf("[FAIL] Test Cost Push Best Single Element B: cost_push_best returned NULL\n");
//     }
    
//     ft_safe_free((void **)&expected);
//     free_stack_memory(stack_a);
//     free_stack_memory(stack_b);
// }

// int main_test_cost_push_best()
// {
//     printf("Démarrage des Tests pour cost_push_best...\n\n");

//     //test_cost_push_best_simple();
//     //test_cost_push_best_sorted_a();
//     //test_cost_push_best_with_rotations();
//     test_cost_push_best_single_element();
//     test_cost_push_best_empty_a();
//     test_cost_push_best_large_stacks();
//     test_cost_push_best_single_element_b();
    
//     printf("\nTous les tests sont terminés.\n");
//     return 0;
// }
