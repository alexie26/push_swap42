/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:51:55 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/03 20:39:44 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	print_stack_reverse(t_stack_node *bottom)
{
	while (bottom)
	{
		printf("%d\n", bottom->nbr);
		bottom = bottom->prev;
	}
}
t_stack_node	*get_bottom(t_stack_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int	main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;

    // Check if there are enough arguments
    if (argc < 2)
    {
        printf("Usage: %s <numbers>\n", argv[0]);
        return (1);
    }

    // Populate stack 'a' with numbers from command-line arguments
    for (int i = 1; i < argc; i++)
    {
        int num = ft_atoi(argv[i]);
        add_node_back(&a, num);
    }

    // Check the number of elements and call the appropriate sorting function
    if (stack_size(a) == 3)
    {
        printf("Sorting 3 elements...\n");
        sort_three(&a); // Ensure sort_three calls operations with print = true
    }
    else if (stack_size(a) == 6)
    {
        printf("Sorting 6 elements...\n");
        push_smallest_three_to_b(&a, &b); // Ensure operations print = true
        sort_three(&a);                  // Ensure operations print = true
        sort_six(&a, &b);                // Ensure operations print = true
    }
    else
    {
        printf("This program only supports sorting 3 or 6 elements.\n");
        return (1);
    }

    return (0);
}
