/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2d_array_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:42:05 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/09 11:27:51 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	strlen_2d(char **map)
{
	int	len;

	len = 0;
	while (map[len] != NULL)
		len++;
	return (len);
}
