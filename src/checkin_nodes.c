/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:06:50 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/08 17:39:34 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_node_pos(t_stack_node *node, int size)
		// positiion in stack based on distace from top
{
	int pos;

	pos = 0;
	// if (!node)
	// 	return (NULL);
	while (node->prev)
	{
		node = node->prev;
		pos++;
	}
	if (pos > size / 2)
		return (size - pos); // if its in second half return reverse
	return (pos);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) // Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

void	create_node(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		exit(1);
	node->nbr = num;
	node->next = NULL;
	node->prev = NULL;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	node_to_top(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
void	add_node_back(t_stack_node **stack, int nbr) //add note to the end of a doubly
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		errer(stack);
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		last = get_bottom(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}