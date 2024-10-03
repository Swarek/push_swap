/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cost_sorting_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:29:19 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/01 10:58:08 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fonction d'assistance pour convertir les rotations en chaîne de caractères
const char *rotation_to_str(int rot) {
    if (rot == ROTATE)
        return "ROTATE________";
    else if (rot == REVERSE_ROTATE)
        return "REVERSE_ROTATE";
    else
        return "UNKNOWN_ROTATION";
}

// Compare les coûts attendus avec les coûts calculés et affiche les résultats
bool assert_cost(t_cost expected, t_cost actual, const char *test_name)
{
	bool pass = true;
	if (expected.nbr != actual.nbr ||
		expected.a_rotations != actual.a_rotations ||
		expected.b_rotations != actual.b_rotations ||
		expected.doing_what_a != actual.doing_what_a ||
		expected.doing_what_b != actual.doing_what_b ||
		expected.cost != actual.cost)
	{
		pass = false;
	}

	if (pass)
		printf("[PASS] %s\n", test_name);
	else
	{
		printf("[FAIL] %s\n", test_name);
		printf("  Expected: cost=%d, nbr=%d, doing_what_a=%s, doing_what_b=%s, a_rotations=%d, b_rotations=%d\n",
			   expected.cost, expected.nbr,
			   rotation_to_str(expected.doing_what_a),
			   rotation_to_str(expected.doing_what_b),
			   expected.a_rotations, expected.b_rotations);
		printf("  Actual:   cost=%d, nbr=%d, doing_what_a=%s, doing_what_b=%s, a_rotations=%d, b_rotations=%d\n",
			   actual.cost, actual.nbr,
			   rotation_to_str(actual.doing_what_a),
			   rotation_to_str(actual.doing_what_b),
			   actual.a_rotations, actual.b_rotations);
	}
	return pass;
}

// Fonctions d'assistance pour les tests

// Crée une pile à partir d'un tableau d'entiers
t_stack *create_stack(int *values, int size) {
	t_stack *head = NULL;
	t_stack *current = NULL;
	t_stack *new_node;
	for(int i = 0; i < size; i++) {
		new_node = ft_safe_malloc(sizeof(t_stack));
		new_node->value = values[i];
		new_node->next = NULL;
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = current->next;
		}
	}
	return head;
}

// Libère la mémoire d'une pile
void free_stack_memory(t_stack *stack) {
	t_stack *tmp;
	while (stack) {
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
// Fonctions de Test

// Test 1: Insertion sans rotation nécessaire
void test_no_rotation_needed() {
	int values_a[] = {2, 1, 3};
	int values_b[] = {};
	t_stack *stack_a = create_stack(values_a, 3);
	t_stack *stack_b = create_stack(values_b, 0);
	t_cost expected = {1, 1, ROTATE, 0, 1, 0}; // cost=2, nbr=1
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 1, &actual);
	assert_cost(expected, actual, "Test No Rotation Needed");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 2: Rotation ascendante dans la pile a
void test_rotate_a_up() {
	int values_a[] = {3, 2, 1, 4};
	int values_b[] = {5, 6};
	t_stack *stack_a = create_stack(values_a, 4);
	t_stack *stack_b = create_stack(values_b, 2);
	t_cost expected = {1, 2, ROTATE, ROTATE, 1, 0}; // cost=1, nbr=2
	t_cost actual = {0, 0, 0, 0, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 2, &actual);
	assert_cost(expected, actual, "Test Rotate A Up");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 3: Rotation descendante dans la pile a
void test_rotate_a_down() {
	int values_a[] = {4, 3, 2, 1};
	int values_b[] = {5, 6};
	t_stack *stack_a = create_stack(values_a, 4);
	t_stack *stack_b = create_stack(values_b, 2);
	t_cost expected = {1, 1, REVERSE_ROTATE, 0, 1, 0}; // cost=1, nbr=1
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 1, &actual);
	assert_cost(expected, actual, "Test Rotate A Down");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 4: Rotation ascendante dans la pile b
void test_rotate_b_up() {
	int values_a[] = {1, 3, 2};
	int values_b[] = {6, 4, 5};
	t_stack *stack_a = create_stack(values_a, 3);
	t_stack *stack_b = create_stack(values_b, 3);
	t_cost expected = {1, 3, ROTATE, ROTATE, 1, 1}; // cost=1, nbr=3
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 3, &actual);
	assert_cost(expected, actual, "Test Rotate B Up");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 5: Rotation descendante dans la pile b
void test_rotate_b_down() {
	int values_a[] = {1, 2, 3};
	int values_b[] = {6, 5, 4};
	t_stack *stack_a = create_stack(values_a, 3);
	t_stack *stack_b = create_stack(values_b, 3);
	t_cost expected = {1, 3, REVERSE_ROTATE, REVERSE_ROTATE, 1, 1}; // cost=1, nbr=3
	t_cost actual = {0, 0, 0, 0, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 3, &actual);
	assert_cost(expected, actual, "Test Rotate B Down");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 6: Rotations simultanées dans la même direction
void test_simultaneous_rotations_same_direction() {
	int values_a[] = {3, 2, 1, 4};
	int values_b[] = {5, 4, 6};
	t_stack *stack_a = create_stack(values_a, 4);
	t_stack *stack_b = create_stack(values_b, 3);
	t_cost expected = {1, 2, ROTATE, ROTATE, 1, 1}; // cost=2, nbr=2
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 2, &actual);
	assert_cost(expected, actual, "Test Simultaneous Rotations Same Direction");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 7: Rotations différentes entre a et b
void test_simultaneous_rotations_different_direction() {
	int values_a[] = {4, 3, 2, 1};
	int values_b[] = {6, 4, 5};
	t_stack *stack_a = create_stack(values_a, 4);
	t_stack *stack_b = create_stack(values_b, 3);
	t_cost expected = {2, 1, REVERSE_ROTATE, ROTATE, 1, 1}; // cost=4, nbr=1
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 1, &actual);
	assert_cost(expected, actual, "Test Simultaneous Rotations Different Direction");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

// Test 8: Rotations différentes entre a et b
void test_8() {
	int values_a[] = {10, 3, 2, 6, 9, 5, 7};
	int values_b[] = {4, 8, 1};
	t_stack *stack_a = create_stack(values_a, 4);
	t_stack *stack_b = create_stack(values_b, 3);
	t_cost expected = {1, 10, 0, ROTATE, 0, 1}; // cost=4, nbr=1
	t_cost actual = {0, 0, ROTATE, ROTATE, 0, 0};
	cost_sorting_nbr(stack_a, stack_b, 10, &actual);
	assert_cost(expected, actual, "Test Simultaneous Rotations Different Direction");
	free_stack_memory(stack_a);
	free_stack_memory(stack_b);
}

int main_test_cost_sorting_nbr(void)
{
	printf("Starting Tests for cost_sorting_nbr...\n\n");
	test_no_rotation_needed();
	test_rotate_a_up();
	test_rotate_a_down();
	test_rotate_b_up();
	test_rotate_b_down();
	test_simultaneous_rotations_same_direction();
	test_simultaneous_rotations_different_direction();
	test_8();
	printf("\nAll tests completed.\n");
	return (0);
}
