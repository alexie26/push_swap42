/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:41:39 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 22:28:53 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*mr_big;

	mr_big = find_max(*a);
	if (mr_big == *a)
		ra(a, true);
	else if ((*a)->next == mr_big)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	current_index(t_stack_node *stack)
{
	int				i;
	int				size;
	t_stack_node	*temp;

	temp = stack;
	i = 0;
	size = stack_len(stack);
	while (temp)
	{
		temp->i = i;
		temp->above_median = (i <= size / 2);
		temp = temp->next;
		i++;
	}
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

int	find_median(t_stack_node *stack, int size)
{
	int *arr;
	t_stack_node *temp;
	int i;
	int median;

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

