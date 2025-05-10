/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:29:12 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:02:36 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	a = *stack;
	b = get_bottom(*stack);
	*stack = a->next;
	(*stack)->prev = NULL;
	b->next = a;
	a->prev = b;
	a->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
