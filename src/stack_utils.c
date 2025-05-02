/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:04:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/02 18:30:21 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// int stack_size(t_stack_node *stack)
// {
// 	int	size = 0;
// 	while (stack)
// 	{
// 		size++;
// 		stack = stack->next;
// 	}
// 	return (size);

// }

//Swap Operations

void swap(t_stack_node **stack)
{
	t_stack_node *a;
	t_stack_node *b;

	if (stack_size(*stack) < 2)
		return;
	a = *stack;
	b = a->next;
	
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;
	b->prev = NULL;
	a->prev = b;
	*stack = b;
}

