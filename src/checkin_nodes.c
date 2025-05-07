/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:06:50 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 21:01:32 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_node_pos(t_stack_node *node, int size)// positiion in stack based on distace from top
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
		last = *stack;
		while (last->next) // Traverse to the last node
            last = last->next;
        last->next = new_node; // Update the last node's next pointer
        new_node->prev = last; 
	}
}

