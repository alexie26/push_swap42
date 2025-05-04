/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:20:25 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/04 16:08:05 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		stack_len(t_stack_node *stack)
{
	int	i;

	i = 0;
	
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
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
			free_split(argv);
			errer(a);
		}
		add_node_back(a, (int)n);
		i++;
	}
}
