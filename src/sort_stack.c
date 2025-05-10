/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:24:15 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->i = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	index_stack(t_stack_node *stack)
{
	t_stack_node	*ptr1;
	t_stack_node	*ptr2;
	int				index;

	if (!stack)
		return ;
	ptr1 = stack;
	while (ptr1)
	{
		index = 0;
		ptr2 = stack;
		while (ptr2)
		{
			if (ptr1->nbr > ptr2->nbr)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->i = index;
		ptr1 = ptr1->next;
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*mr_big;

	mr_big = find_max(*a);
	if (mr_big == *a)
		ra(a);
	else if ((*a)->next == mr_big)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	pushed;

	pushed = 0;
	index_stack(*a);
	while (pushed < 2)
	{
		if ((*a)->i == 0 || (*a)->i == 1)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	sort_three(a);
	if (*b && (*b)->next && (*b)->i < (*b)->next->i)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	index_stack(*a);
	size = stack_len(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->i >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
	}
}
