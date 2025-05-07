/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:29:12 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 20:28:37 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"


void	rotate(t_stack_node **stack)
{
	t_stack_node *a;
	t_stack_node *b;

	if (!stack || !*stack || !(*stack)->next)
		return;
	
	a = *stack;//top of stack
	b = get_bottom(*stack); //bottom
	*stack = a->next; //top on the second 
	(*stack)->prev = NULL; //the prev is now the top

	b->next = a;
	a->prev = b;
	a->next = NULL; //first is now last
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
		if(print)
			ft_printf("rr\n");
}

//  - ra: Shift all the nodes of stack A up by 1. The first element becomes last.
//  - rb: Shift all the nodes of Stack B up by one.
//  - rr: ra amd rb at the same time