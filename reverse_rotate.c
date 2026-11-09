/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:18:08 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/09 17:12:36 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **x)
{
	t_node	*first;
	t_node	*last;
	t_node	*pre_last;

	if (!x || !*x || !(*x)->next)
		return ;
	first = *x;
	pre_last = first;
	last = first->next;
	while (last->next)
	{
		pre_last = last;
		last = last->next;
	}
	*x = last;
	last->next = first;
	pre_last->next = NULL;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
