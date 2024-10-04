/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:00:28 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 09:41:31 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Quand je reecrirai ce programme, penser a chercher si c'est possible de 
// faire des swaps avec les nombres a cotes des LIS

#include "push_swap.h"

// Convertit stack_a en un tableau d'entiers
static int	*convert_stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = ft_safe_malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

// Initialise les tableaux lis_length et prev
static void	initialize_lis_arrays(int *lis_length, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis_length[i] = 1;
		prev[i] = -1;
		i++;
	}
}

// Calcule la LIS et retourne l'index de son dernier élément
static int	compute_lis(int *arr, int size, int *lis_length, int *prev)
{
	int	i;
	int	j;
	int	max_len;
	int	max_index;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis_length[i] < lis_length[j] + 1)
			{
				lis_length[i] = lis_length[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
	max_len = 0;
	max_index = 0;
	i = 0;
	while (i < size)
	{
		if (lis_length[i] > max_len)
		{
			max_len = lis_length[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

// Reconstruit la LIS à partir des indices précédents
static int	*reconstruct_lis(int *arr, int *prev, int lis_length_val, int max_index)
{
	int		i;
	int		*lis;

	lis = malloc(sizeof(int) * lis_length_val);
	if (!lis)
		return (NULL);
	i = lis_length_val - 1;
	while (i >= 0)
	{
		lis[i] = arr[max_index];
		max_index = prev[max_index];
		i--;
	}
	return (lis);
}

// Trouve la LIS dans stack_a et retourne un tableau contenant les éléments de la LIS
// LIS = Longest Increasing Subsequence
int	*find_lis(t_stack *stack_a, int *lis_length)
{
	int		size;
	int		*arr;
	int		*lis_length_arr;
	int		*prev;
	int		max_index;
	int		*lis;

	size = stack_length(stack_a);
	arr = convert_stack_to_array(stack_a, size);
	if (!arr)
		return (NULL);
	lis_length_arr = malloc(sizeof(int) * size);
	if (!lis_length_arr)
	{
		free(arr);
		return (NULL);
	}
	prev = malloc(sizeof(int) * size);
	if (!prev)
	{
		free(arr);
		free(lis_length_arr);
		return (NULL);
	}
	initialize_lis_arrays(lis_length_arr, prev, size);
	max_index = compute_lis(arr, size, lis_length_arr, prev);
	*lis_length = lis_length_arr[max_index];
	lis = reconstruct_lis(arr, prev, *lis_length, max_index);
	free(arr);
	free(lis_length_arr);
	free(prev);
	return (lis);
}
