/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:20:25 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/09 17:28:49 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i  = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)	
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_min(t_stack_node *a)
{
	t_stack_node	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->nbr < min->nbr)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack_node	*find_max(t_stack_node *a)
{
	t_stack_node	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (a->nbr > max->nbr)
			max = a;
		a = a->next;
	}
	return (max);
}

