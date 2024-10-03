/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates_t_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:13:01 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/24 03:11:21 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_search	*initialize_search(void)
{
	t_search	*search;

	search = ft_safe_malloc(sizeof(t_search));
	//search->nbrs_list = NULL;
	search->range = 10;
	search->approx = 40;
	search->highest_tryable = 100;
	return (search);
}

/* Updates the t_search structure with new values
and frees existing nbrs_list */
void	update_search(t_search *search, int range, int approx, int highest)
{
	// if (search->nbrs_list)
	// {
	// 	free_in_range(search->nbrs_list);
	// 	search->nbrs_list = NULL;
	// }
	search->range = range;
	search->approx = approx;
	search->highest_tryable = highest;
	search->in_range = 0;
	search->best_target = 0;
	//search->nbrs_list = NULL;
}
