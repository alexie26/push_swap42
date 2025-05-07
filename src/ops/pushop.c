/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:23:12 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 20:27:57 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *node;
	
	if (!*b)
		return ;
	node = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	node->prev = NULL;
	if (!*a)
	{
		*a = node;
		node->next = NULL;
	}
	else
	{
		node->next = *a;
		node->next->prev = node;
		*a = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

 // Push Operations
 //- pa: Top node of B on top of A
 //- pb: Top node of A on top of B