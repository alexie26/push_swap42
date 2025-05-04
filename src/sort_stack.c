/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/04 19:05:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_index(t_stack_node *stack, t_stack_node *node)
{
    int	index;

    index = 0;
    while (stack)
    {
        if (stack == node)
            return (index);
        stack = stack->next;
        index++;
    }
    return (-1); // Node not found
}

int	stack_issorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
	t_stack_node	*mr_small;

	while(stack_size(*a) > 4)
	{
		mr_small = find_min(*a);
		while (*a != mr_small)
		{
			if (get_index(*a, mr_small) <= stack_size(*a) / 2)
				ra(a, true);
			else
				rra(a, true);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
