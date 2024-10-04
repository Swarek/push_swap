/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cost_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:58:52 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 06:59:49 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	*t_cost_dup(t_cost *original)
{
	t_cost	*dup;

	if (!original)
		return (NULL);
	dup = malloc(sizeof(t_cost));
	if (!dup)
		return (NULL);
	dup->cost = original->cost;
	dup->lis_length = original->lis_length;
	dup->nbr = original->nbr;
	dup->doing_what_a = original->doing_what_a;
	dup->doing_what_b = original->doing_what_b;
	dup->a_rotations = original->a_rotations;
	dup->b_rotations = original->b_rotations;
	if (original->lis_length > 0 && original->lis)
	{
		dup->lis = malloc(sizeof(int) * original->lis_length);
		if (!dup->lis)
			return (free(dup), NULL);
		for (int i = 0; i < original->lis_length; i++)
			dup->lis[i] = original->lis[i];
	}
	else
		dup->lis = NULL;
	return (dup);
}
