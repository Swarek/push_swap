/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:35:27 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/16 02:34:17 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_arguments(char **args)
{
	t_stack	*head;

	if (!args[0])
		return (NULL);
	head = strings_to_stack(args);
	return (head);
}
