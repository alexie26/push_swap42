/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/03 20:29:21 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"


void	sort_three(t_stack_node **a)
{
	t_stack_node *mr_big;
		
	mr_big = find_max(*a);
	if (mr_big == *a)
		ra(a, true);
	else if ((*a)->next == mr_big)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);	
}

void	sort_six(t_stack_node **a, t_stack_node **b)
{
	sort_three(a);
	push_biggest_three_to_a(a, b);
	t_stack_node *mr_big;

	mr_big = find_max(*a);
	if (mr_big == *a)
		ra(a, true);
	else if ((*a)->next == mr_big)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}
