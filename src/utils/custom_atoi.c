/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:36:08 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 16:19:16 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	custom_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (result > (INT_MAX / 10)))
			return (ft_error_msg(""), -1);
		if (sign == -1 && (result > (-INT_MIN / 10)))
			return (ft_error_msg(""), -1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
