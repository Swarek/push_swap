/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:53:32 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 03:18:43 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sqrt_int(int number)
{
	int	start;
	int	mid;
	int	end;
	int	result;

	if (number == 0 || number == 1 || number < 0)
		return (number);
	start = 1;
	end = number;
	result = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid == number / mid)
			return (mid);
		if (mid < number / mid)
		{
			start = mid + 1;
			result = mid;
		}
		else
			end = mid - 1;
	}
	return (result);
}

