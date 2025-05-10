/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:51:55 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:22:21 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_dublicate(t_stack_node *stack, int num)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == num)
			return (1);
		stack = stack->next;
	}
	return (0);
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

int	special_split(t_stack_node **stack, char *input)
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
			return (free_split(split), errer(stack), 1);
		add_node_back(stack, (int)num);
		i++;
	}
	return (free_split(split), 1);
}

t_stack_node	*parse_argv_into_stack(int argc, char **argv, t_stack_node **a)
{
	int		i;
	long	num;

	i = 1;
	if (argc == 2)
		special_split(a, argv[1]);
	else
	{
		while (i < argc)
		{
			if (!ft_isnumeric(argv[i]))
				errer(a);
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN || is_dublicate(*a, (int)num))
				errer(a);
			add_node_back(a, (int)num);
			i++;
		}
	}
	return (*a);
}

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				n;

	n = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = parse_argv_into_stack(argc, argv, &a);
	if (stack_len(a) > 1)
		full_sort(&a, &b);
	free_stack(&a);
	return (0);
}
