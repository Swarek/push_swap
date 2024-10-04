/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:18 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 06:21:37 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


// cost = price to go to nbr in a and rotate b to push it.
typedef struct s_cost
{
	int	cost;

	int	*lis;
	int	lis_length;
	int	nbr;
	int	doing_what_a;
	int	doing_what_b;
	int	a_rotations;
	int	b_rotations;
}	t_cost;
// Cost = the number of moves to do to push a number to b.
// Benefits = The benefits of a move.
// 		It's worth the number of moves saved.
// profit_ratio = (ALPHA * Total_cost + BETA * Benefits) / Total_cost
//		(Costs / Benefits ratio)

// typedef struct s_cost
// {
// 	int				cost;
// 	int				benefits;
// 	int				net_gain;
// 	t_data			*doing_what;
// 	struct s_cost	*t_cost;
// }	t_cost;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// --------------
// Ne pas prendre en compte la valeur target, 
// elle est utilisee que dans certaines fonctions
// Mais je n'ai pas besoin de gerer cette valeur.
typedef struct s_search
{
	int			range;
	int			approx;
	int			highest_tryable;
	int			best_target;
	int			in_range;
	int			target;
	//t_in_range	*nbrs_list;
}	t_search;

typedef struct s_val
{
	int	start_value;
	int	end_value;
}	t_val;

#endif