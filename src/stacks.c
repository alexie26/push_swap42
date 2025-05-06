/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:08:26 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/06 18:16:59 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	stack_size(t_stack_node *stack) //counting the number of nodes in a doubly linked list
{
	int	size;

	size = 0;
	while (stack && stack->prev) //go to head in case curr is in the middle
		stack = stack->prev;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size); //outputs how many nodes
}

