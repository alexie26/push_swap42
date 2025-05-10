/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:26 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:21:20 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack_node	*find_best_pos(t_stack_node *a, int nbr)
{
	t_stack_node	*best;

	best = a;
	while (a)
	{
		if (a->nbr > nbr && (!best || a->nbr < best->nbr))
			best = a;
		a = a->next;
	}
	return (best);
}

t_stack_node	*get_bottom(t_stack_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	full_sort(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len <= 1 || is_sorted(*a))
		return ;
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 5)
	{
		index_stack(*a);
		sort_five(a, b);
	}
	else
	{
		index_stack(*a);
		radix_sort(a, b);
	}
}
