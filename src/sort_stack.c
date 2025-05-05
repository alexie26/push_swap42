/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/05 19:14:42 by roalexan         ###   ########.fr       */
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
	pb(a, a);
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

t_stack_node	*find_target_node(t_stack_node *b, int value)
{
	t_stack_node	*curr;
	t_stack_node	*smoll;
	t_stack_node	*big;

	if (!b || !b->next)
		return (b);
	curr = b;
	smoll = b;
	big = b;
	while (curr)
	{
		if (curr->nbr < smoll->nbr)
			smoll = curr;
		if (curr->nbr > big->nbr)
			big = curr;
		curr = curr->next;
	}
	curr = b;
	while (curr->next)
	{
		if (value > curr->nbr && value < curr->next->nbr)
			return (curr->next);
		curr = curr->next;
	}
	if (value < smoll->nbr)
		return (smoll);
	if (value > big->nbr)
		return (big);
	return (b);
}

void	push_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;
	t_stack_node	*node_to_push;
	int				pos;
	int				size;

	if (!*a)
		return ;
	node_to_push = *a;
	target = find_target_node(*b, node_to_push->nbr);
	if (!target)
		return ;
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
	if (*b && (*b)->next && (*b)->nbr > (*b)->next->nbr)
		sb(b, true);
}
