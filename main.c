/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:51:55 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/02 18:36:00 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node	*get_bottom(t_stack_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d", stack->nbr);
		stack = stack->next;
	}
}

void	print_stack_reverse(t_stack_node *bottom)
{
	while (bottom)
	{
		printf("%d\n", bottom->nbr);
		bottom = bottom->prev;
	}
}

t_stack_node	*find_min(t_stack_node *a)
{
	t_stack_node	*min;

	while (a)
	{
		if (a->nbr < min->nbr)
			min = a;
		a = a->next;
	}
	return (min);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	if (!*a)
		return ;
	node = *a;
	*a = node->next;
	if (*a)
		(*a)->prev = NULL;
	node->next = *b;
	if (*b)
		(*b)->prev = node;
	*b = node;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	if (!*b)
		return ;
	node = *b;
	*b = node->next;
	if (*b)
		(*b)->prev = NULL;
	node->next = *a;
	if (*a)
		(*a)->prev = node;
	*a = node;
}

void	add_node_back(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		last = get_bottom(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}
// void sort_three(t_stack_node **a)
// {
//     int n1 = (*a)->nbr;
//     int n2 = (*a)->next->nbr;
//     int n3 = (*a)->next->next->nbr;

//     if (n1 > n2 && n2 < n3 && n1 < n3)
//         sa(a);
//     else if (n1 > n2 && n2 > n3)
//     {
//         sa(a);
//         rra(a);
//     }
//     else if (n1 > n2 && n2 < n3 && n1 > n3)
//         ra(a);
//     else if (n1 < n2 && n2 > n3 && n1 < n3)
//     {
//         sa(a);
//         ra(a);
//     }
//     else if (n1 < n2 && n2 > n3 && n1 > n3)
//         rra(a);
// }

int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		int num = ft_atoi(argv[i]);
		add_node_back(&a, num);
	}
	print_stack(a);
	return (0);
}