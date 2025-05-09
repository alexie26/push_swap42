/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:12:15 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/09 18:23:09 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "getnextline42/get_next_line.h"
# include "libft-42/libft.h"
# include "printf42/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483647

// nbr: 			value of the node (original number)
// i: 			index to sort over
// push_cost:	number of operations to move to the correct pos
// above_median:	optimize rotate directopn (ra/rra or rb/rrb)
// cheapest:		flag to mark the node with the last push_cost

// target_node	node in the other stack where this one should
// next			next node in stack (singly/double linked list)
// prev			prev node (reverse traversal)

// dobule linked list forward and backwards traverse
// node countains a pointer to the next node and a pointer to the previous

// Turk Algorithm
// 1. Calculate the best pos in Stack A for each number in Stack B
// 2. Computes the cheapest combination of moves (the sa, sb, ss, etcc.....)
// to push that number from B to A / A to Byurrrrr
// 3. Execute with the lower total cost

typedef struct s_stack_node
{
	int					nbr;
	int					i;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	int					value;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Stack utils
t_stack_node			*find_min(t_stack_node *a);
t_stack_node			*find_max(t_stack_node *a);

void					sort_three(t_stack_node **a);
void					sort_five(t_stack_node **a, t_stack_node **b);
void					current_index(t_stack_node *stack);

// main
void					free_stack(t_stack_node **stack);
t_stack_node			*get_bottom(t_stack_node *stack);
int						main(int argc, char **argv);

// push_operations;
void					push(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);
void					pa(t_stack_node **a, t_stack_node **b);
// swap op
void					swap(t_stack_node **top);
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
// rotate op
void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
// reverse op
void					reverse(t_stack_node **stack);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// Parseee

long					ft_atol(const char *s);
int						stack_len(t_stack_node *stack);
int						get_node_pos(t_stack_node *node, int size);

// Init
int						is_dublicate(t_stack_node *stack, int num);
void					free_split(char **split);
void					errer(t_stack_node **stack);

void	add_node_back(t_stack_node **stack, int nbr);

void	current_index(t_stack_node *stack);
void	bubble_sort(int *array, int len);
int		find_median(t_stack_node *stack, int size);

int	is_sorted(t_stack_node *stack);
void	radix_sort(t_stack_node **a, t_stack_node **b);
void	index_stack(t_stack_node *stack);




#endif