/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/06 18:55:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_index(t_stack_node *stack, t_stack_node *node)
{
    int	index;

    index = 0;
    while (stack)
    {
        printf("Debug: Traversing stack, current node = %p, target node = %p\n", stack, node);
        if (stack == node)
        {
            printf("Debug: get_index found node at index = %d\n", index);
            return (index);
        }
        stack = stack->next;
        index++;
    }
    printf("Debug: get_index did not find the node\n");
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

void	push_firsttwo(t_stack_node **a, t_stack_node **b)
{
	pb(a, b);
	pb(a, b);
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

void	find_target_nodes(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*curr_b;
	t_stack_node	*best_match;
	int				best_diff;

	curr_a = a;
	while (curr_a)
	{
		curr_b = b;
		best_diff = INT_MAX;
		best_match = NULL;
		while (curr_b)
		{
			// For descending order: we find the first smaller value
			if (curr_b->nbr < curr_a->nbr && (curr_a->nbr
					- curr_b->nbr) < best_diff)
			{
				best_diff = curr_a->nbr - curr_b->nbr;
				best_match = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (!best_match)
			best_match = find_max(b);
		curr_a->target_node = best_match;
		curr_a = curr_a->next;
	}
}

void	push_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_to_push;
	t_stack_node	*target;
	int				pos;
	int				size;

	if (!*a)
		return ;
	find_target_nodes(*a, *b);
	node_to_push = *a;
	target = node_to_push->target_node;
	if (!target)
	{
		pb(a, b);
		return ;
	}
	pos = get_node_pos(target, stack_size(*b));
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (*b != target)
			rb(b, true);
	}
	else
	{
		while (*b != target)
			rrb(b, true);
	}
	pb(a, b);
	// Optional: keep B sorted by swapping if needed
	if (*b && (*b)->next && (*b)->nbr < (*b)->next->nbr)
		sb(b, true);
}

void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;
	int				pos;
	int				size;

	while (*b)
	{
		max_node = find_max(*b);
		pos = get_index(*b, max_node);
		size = stack_size(*b);
		if (pos <= size / 2)
			while (*b != max_node)
				rb(b, true);
		else
			while (*b != max_node)
				rrb(b, true);
		pa(a, b);
	}
}

void	final_rotate(t_stack_node **a)
{
	t_stack_node	*min;
	int				pos;
	int				size;

	min = find_min(*a);
	pos = get_index(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (*a != min)
			ra(a, true);
	else
		while (*a != min)
			rra(a, true);
}

void	push_smallest_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while (*a != min_node)
	{
		// printf("Debug: *a = %p, min_node = %p, get_index = %d\n", *a, min_node,
		// 	get_index(*a, min_node));
		if (get_index(*a, min_node) <= stack_size(*a) / 2)
			ra(a, true);
		else
			rra(a, true);
	}
	pb(a, b);
}

void	full_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 4 || size == 5 || size == 6)
	{
		while (stack_size(*a) > 3)
			push_smallest_to_b(a, b);
		sort_three(a);
		while (*b)
			pa(a, b);
	}
	else
	{
		while (stack_size(*a) > 3)
			push_target_node(a, b);
		sort_three(a);
		push_back_to_a(a, b);
		final_rotate(a);
	}
}
