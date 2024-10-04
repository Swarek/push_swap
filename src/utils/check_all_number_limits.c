/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_number_limits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:03:58 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 16:18:57 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif_limit_str(char *str)
{
	int		j;
	int		sign;
	long	nbr;

	j = 0;
	nbr = 0;
	sign = 1;
	if (str[j] == '-')
	{
		sign = -1;
		j++;
	}
	if (!ft_isdigit(str[j]))
		return (ft_error_msg(""), -1);
	while (str[j] >= '0' && str[j] <= '9')
	{
		if ((sign == 1 && (nbr * 10 + (str[j] - '0') > INT_MAX)
				|| (sign == -1 && -(nbr * 10 + (str[j] - '0')) < INT_MIN)))
			return (ft_error_msg(""), -1);
		nbr = nbr * 10 + (str[j++] - '0');
	}
	if (str[j] != '\0')
		return (ft_error_msg(""), -1);
	return (0);
}

int	check_all_number_limits(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		if (verif_limit_str(strs[i]) == -1)
			return (-1);
	}
	return (0);
}
