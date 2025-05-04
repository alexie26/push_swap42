/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:51:55 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/04 17:43:48 by roalexan         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (argc == 1 && (argc == 2 || !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			free_split(args);
			return (1);
		}
		stack_init(&a, args);
		free_split(args);
	}
	  else
        stack_init(&a, argv + 1);
    if (stack_issorted(a))
    {
        free_stack(&a);
        return (0);
    }
    if (stack_size(a) <= 3)
        sort_three(&a);
    else if (stack_size(a) <= 6)
        sort_six(&a, &b);
    else
    {
        push_smallest_three_to_b(&a, &b);
        push_biggest_three_to_a(&a, &b);
    }
    free_stack(&a);
    free_stack(&b);
    return (0);
}

