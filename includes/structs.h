/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:18 by mblanc            #+#    #+#             */
/*   Updated: 2024/10/04 12:25:39 by mblanc           ###   ########.fr       */
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

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

#endif