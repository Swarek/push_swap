/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:45:03 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/10 21:57:02 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t old_count, size_t new_count)
{
	void	*new_ptr;
	size_t	copy_count;

	if (new_count == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_count * sizeof(char *)));
	new_ptr = malloc(new_count * sizeof(char *));
	if (!new_ptr)
		return (NULL);
	if (old_count < new_count)
		copy_count = old_count;
	else
		copy_count = new_count;
	ft_memcpy(new_ptr, ptr, copy_count * sizeof(char *));
	free(ptr);
	return (new_ptr);
}
