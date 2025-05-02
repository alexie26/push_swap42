/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:12:15 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/02 18:30:45 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "getnextline42/get_next_line.h"
# include "libft-42/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

//nbr: 			value of the node (original number)
//i: 			index to sort over
//push_cost:	number of operations to move to the correct pos
//above_median:	optimize rotate directopn (ra/rra or rb/rrb)
//cheapest:		flag to mark the node with the last push_cost

//target_node	node in the other stack where this one should
//next			next node in stack (singly/double linked list)
//prev			prev node (reverse traversal)

//dobule linked list forward and backwards traverse

// Turk Algorithm
// 1. Calculate the best pos in Stack A for each number in Stack B
// 2. Computes the cheapest combination of moves (the sa, sb, ss, etcc.....)
// to push that number from B to A / A to Byurrrrr
// 3. Execute with the lower total cost


typedef struct s_stack_node
{
	int		nbr;
	int		i;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

//Handle Errors


//Stack init

//Nodes init

//Stack utils

//Commands

//Algorimthms
int	stack_size(t_stack_node *stack);


#endif