/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 15:35:22 by roalexan         ###   ########.fr       */
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
        {
            return (index);
        }
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
	int	i;
	int	size;
	t_stack_node *temp;
	
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
	t_stack_node *min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
t_stack_node	*find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheap_node;
	int				min_cost;

	if (!stack)
		return (NULL);
	cheap_node = stack;
	while (stack)
	{
		stack->cheapest = false;
		stack = stack->next;
	}
	stack = cheap_node;
	cheap_node = stack;
	min_cost = stack->push_cost;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	if (cheap_node)
		cheap_node->cheapest = true;
	return (cheap_node);
}


//push and rotation

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void rrr_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest;
	cheapest = find_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rrr_both(a, b, cheapest);
	
}