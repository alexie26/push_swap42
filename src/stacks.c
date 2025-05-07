/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:26 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 22:34:27 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack_node *find_best_pos(t_stack_node *a, int nbr)
{
	t_stack_node *best;

	best = a;
	while (a)
	{
		if (a->nbr > nbr && (!best || a->nbr < best->nbr))
			best = a;
		a = a->next;
	}
	return (best);
}

