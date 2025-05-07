/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:49:14 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 16:54:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

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

void	errer(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error!\n");
	exit(1);
}

void	stack_init(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i])
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || is_dublicate(*a, n))
		{
			// free_split(argv);
			errer(a);
		}
		add_node_back(a, (int)n);
		i++;
	}
}