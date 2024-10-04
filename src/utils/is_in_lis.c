/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:24:17 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 07:03:54 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_lis(int nbr, int *lis, int lis_length)
{
	int	i;

	i = 0;
	while (i < lis_length)
	{
		if (lis[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
