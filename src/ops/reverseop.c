/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:40:57 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:02:55 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	reverse(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = get_bottom(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	reverse(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	reverse(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}

//  - rra: Bottom node to the top and shifting the nodes of A down.
//  - rrb: Bottom ndoe to the top and shifting the nodes of B down.