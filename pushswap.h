/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:12:15 by roalexan          #+#    #+#             */
/*   Updated: 2025/05/07 20:46:20 by roalexan         ###   ########.fr       */
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

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Stack utils
int						stack_size(t_stack_node *stack);

t_stack_node			*find_min(t_stack_node *a);
t_stack_node			*find_max(t_stack_node *a);


void	sort_three(t_stack_node **a);
int	check_if_sorted(t_stack_node *stack);
void	current_index(t_stack_node *stack);
void	min_on_top(t_stack_node **a);
t_stack_node	*find_cheapest(t_stack_node *stack);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	rrr_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_to_b(t_stack_node **a, t_stack_node **b);




void full_sort(t_stack_node **a, t_stack_node **b);



// main
void	free_stack(t_stack_node **stack);
t_stack_node			*get_bottom(t_stack_node *stack);
int						main(int argc, char **argv);

// push_operations;
void	push(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
// swap op
void					swap(t_stack_node **stack);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
// rotate op
void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
// reverse op
void					reverse(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);

// Parseee

long	ft_atol(const char *s);

void	stack_init(t_stack_node **a, char **argv);
int						stack_len(t_stack_node *stack);
int						get_node_pos(t_stack_node *node, int size);
void					add_node_back(t_stack_node **stack, int nbr);

// Init
int						is_dublicate(t_stack_node *stack, int num);
void					free_split(char **split);
void					errer(t_stack_node **stack);

#endif