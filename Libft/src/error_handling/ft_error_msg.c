/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:32:54 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/10 21:46:13 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error_msg(const char *msg)
{
	if (msg)
	{
		write(2, BOLD_COLOR_RED, 8);
		write(2, "Error", 5);
		while (*msg)
		{
			write(2, msg, 1);
			msg++;
		}
		write(2, RESET_COLOR, 4);
		write(2, "\n", 1);
	}
	return (-1);
}
