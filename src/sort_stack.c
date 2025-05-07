/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 21:00:01 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"



void	sort_three(t_stack_node **a)
{
	t_stack_node	*mr_big;

	mr_big = find_max(*a);
	if (mr_big == *a)
		ra(a, true);
	else if ((*a)->next == mr_big)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	current_index(t_stack_node *stack)
{
	int				i;
	int				size;
	t_stack_node	*temp;

	temp = stack;
	i = 0;
	size = stack_len(stack);
	while (temp)
	{
		temp->i = i;
		temp->above_median = (i <= size / 2);
		temp = temp->next;
		i++;
	}
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
