/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/09 18:22:09 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// void	current_index(t_stack_node *stack)
// {
// 	int				i;
// 	int			median;

// 	i = 0;
// 	if (!stack)
// 		return ;
// 	median = stack_len(stack) / 2; //lenght of stack half
// 	while (stack)
// 	{
// 		stack->i = i;
// 		if (i <= median)
// 			stack->above_median = true;
// 		else
// 			stack->above_median = false;
// 		stack = stack->next;
// 		++i; //index increment beofre to set the next node
// 	}
// }

void	current_index(t_stack_node *stack)
{
	t_stack_node	*ptr1;
	t_stack_node	*ptr2;
	int				index;

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
		ptr1->i = index; // Assign the calculated index to the node
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

void	bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_len(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (*a && (((*a)->i >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		printf("yurr\n");
		while (*a)
			pa(b, a);
		i++;
	}
}

int	find_median(t_stack_node *stack, int size)
{
	int				*arr;
	t_stack_node	*temp;
	int				i;
	int				median;

	arr = malloc(sizeof(int) * size);
	i = 0;
	temp = stack;
	while (temp)
	{
		arr[i++] = temp->nbr;
		temp = temp->next;
	}
	bubble_sort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
