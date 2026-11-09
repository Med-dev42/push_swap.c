/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:43:25 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/09 17:14:43 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

void	swap(t_node **n);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	push(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	rotate(t_node **c);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	reverse_rotate(t_node **x);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
