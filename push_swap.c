/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:51:55 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/06 18:15:27 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
t_stack_node	*get_bottom(t_stack_node *stack) // bottom of stack
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
int	ft_isnumeric(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**special_split(t_stack_node **stack, char *input)
{
	char	**split;
	int		i;
	long	num;

	split = ft_split(input, ' ');
	if (!split || !split[0])
	{
		free_split(split);
		errer(stack);
	}
	i = 0;
	while (split[i])
	{
		if (!ft_isnumeric(split[i]))
		{
			free_split(split);
			errer(stack);
		}
		num = ft_atol(split[i]);
		if (num > INT_MAX || num < INT_MIN || is_dublicate(*stack, (int)num))
		{
			free_split(split);
			errer(stack);
		}
		add_node_back(stack, (int)num);
		i++;
	}
	return (split);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		special_split(&a, argv[1]);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (!ft_isnumeric(argv[i]) || ft_atol(argv[i]) > INT_MAX
				|| ft_atol(argv[i]) < INT_MIN || is_dublicate(a,
					ft_atoi(argv[i])))
				errer(&a);
			add_node_back(&a, ft_atoi(argv[i]));
		}
	}
	if (stack_issorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size(a) <= 3)
		sort_three(&a);
	else
		full_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
