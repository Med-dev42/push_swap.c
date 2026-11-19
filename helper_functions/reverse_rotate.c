/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:18:08 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:10:00 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rra(t_logic *c)
{
	reverse_rotate(&c->a);
	c->count[RRA]++;
	write(1, "rra\n", 4);
}

void	rrb(t_logic *c)
{
	reverse_rotate(&c->b);
	c->count[RRB]++;
	write(1, "rrb\n", 4);
}

void	rrr(t_logic *c)
{
	reverse_rotate(&c->a);
	reverse_rotate(&c->b);
	c->count[RRR]++;
	write(1, "rrr\n", 4);
}
