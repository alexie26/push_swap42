/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:12:03 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 15:10:07 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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

t_stack_node	*find_extreme(t_stack_node *stack, t_stack_node *exclude[],
		int count, bool find_min)
{
	t_stack_node	*extreme;
	bool			skip;
	int				i;

	extreme = NULL;
	while (stack)
	{
		skip = false;
		i = 0;
		while (i < count)
		{
			if (stack == exclude[i])
			{
				skip = true;
				break ;
			}
			i++;
		}
		if (!skip)
		{
			if (extreme == NULL)
				extreme = stack;
			else if (find_min && stack->nbr < extreme->nbr)
				extreme = stack;
			else if (!find_min && stack->nbr > extreme->nbr)
				extreme = stack;
		}
		stack = stack->next;
	}
	return (extreme);
}

t_stack_node	*find_min_exclude(t_stack_node *stack, t_stack_node *exclude[],
		int count)
{
	return (find_extreme(stack, exclude, count, true));
}

t_stack_node	*find_max_exclude(t_stack_node *stack, t_stack_node *exclude[],
		int count)
{
	return (find_extreme(stack, exclude, count, false));
}

void	push_smallest_three_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*exclude[3] = {NULL, NULL, NULL};
	int				ex_count;
	t_stack_node	*min_node;

	ex_count = 0;
	while (ex_count < 3)
	{
		min_node = find_min_exclude(*a, exclude, ex_count);
		if (!min_node)
			break ;
		exclude[ex_count] = min_node;
		ex_count++;
		pb(a, b);
	}
}

void	push_biggest_three_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*exclude[3] = {NULL, NULL, NULL};
	int				ex_count;
	t_stack_node	*max_node;

	ex_count = 0;
	while (ex_count < 3)
	{
		max_node = find_max_exclude(*b, exclude, ex_count);
		if (!max_node)
			break ;
		exclude[ex_count] = max_node;
		ex_count++;
		pa(a, b);
	}
}
