/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:21:20 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/10 17:04:23 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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

void	free_stack(t_stack_node **stack)
{
	while (*stack)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
}
