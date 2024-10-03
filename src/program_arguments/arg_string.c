/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:12:49 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 03:06:55 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*strings_to_stack(char **strs)
{
	t_stack	*head;
	t_stack	*current;
	int		i;
	int		j;

	i = 0;
	head = create_stack_node(ft_atoi(strs[i++]));
	current = head;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
				return (NULL);
			j++;
		}
		current->next = create_stack_node(ft_atoi(strs[i]));
		current = current->next;
		i++;
	}
	return (head);
}

static int	validate_no_multiple_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
		return (ft_error_msg("Space at the beggining of the string"));
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ' ')
			i++;
		if (str[i] == ' ')
			return (ft_error_msg("Several spaces between numbers"));
	}
	if (str[i - 1] == ' ')
		return (ft_error_msg("Space at the end of the string"));
	return (0);
}

t_stack	*parse_string_argument(char *arg)
{
	char	**strs;
	t_stack	*head;

	if (validate_no_multiple_spaces(arg) == -1)
		return (NULL);
	strs = ft_split(arg, ' ');
	head = strings_to_stack(strs);
	safe_free_all_strings(&strs);
	return (head);
}
