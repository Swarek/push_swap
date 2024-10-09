/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:12:49 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 18:36:07 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_node(int value)
{
	t_stack	*new;

	new = (t_stack *)ft_safe_malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

t_stack	*strings_to_stack(char **strs)
{
	t_stack	*head;
	t_stack	*current;
	int		i;
	int		j;
	int		debug;

	i = 0;
	debug = ft_atoi(strs[i++]);
	head = create_stack_node(debug);
	current = head;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j]) && strs[i][j] != '-')
				return (clear_stack(&head), NULL);
			j++;
		}
		debug = ft_atoi(strs[i++]);
		current->next = create_stack_node(debug);
		current = current->next;
	}
	return (head);
}

int	validate_no_multiple_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
		return (ft_error_msg(""));
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ' ')
			i++;
		if (str[i] == ' ')
			return (ft_error_msg(""));
		if (str[i] == '-')
			i++ ;
		if (str[i] != ' ' && str[i] != '\0' && !(str[i] >= '0'
				&& str[i] <= '9') && str[i] != '-')
		{
			return (ft_error_msg(""));
		}
	}
	if (str[i - 1] == ' ')
		return (ft_error_msg(""));
	return (0);
}

t_stack	*parse_string_argument(char *arg)
{
	char	**strs;
	t_stack	*head;

	if (validate_no_multiple_spaces(arg) == -1)
		return (NULL);
	strs = ft_split(arg, ' ');
	if (!(*strs))
		return (safe_free_all_strings(&strs), NULL);
	if (check_all_number_limits(strs) == -1)
		return (safe_free_all_strings(&strs), NULL);
	head = strings_to_stack(strs);
	safe_free_all_strings(&strs);
	if (verif_duplicate(head))
		return (ft_error_msg(""), clear_stack(&head), NULL);
	return (head);
}
