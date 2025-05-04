/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:04:42 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/04 13:15:22 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (stack_size(*stack) < 2)
		return ;
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

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
	{
		ft_printf("sb\n");
	}
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
