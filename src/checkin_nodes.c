/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:06:50 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/05 19:02:03 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_node_pos(t_stack_node *node, int size)
// positiion in stack based on distace from top
{
	int pos;

	pos = 0;
	while (node->prev)
	{
		node = node->prev;
		pos++;
	}
	if (pos > size / 2)
		return (size - pos); // if its in second half return reverse
	return (pos);
}

void	add_node_back(t_stack_node **stack, int nbr)
// add note to the end of a doubly
{
	t_stack_node *new_node;
	t_stack_node *last;

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

int	calc_cost(t_stack_node *stack)
{
	int	size;
	int	i;

	size = stack_size(stack);
	i = 0;
	while (stack)
	{
		if (i <= size / 2)
			stack->push_cost = i;
		else
			stack->push_cost = size - i;
		stack = stack->next;
		i++;
	}
	return (0);
}

