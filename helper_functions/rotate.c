/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:02:08 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:06:11 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **c)
{
	t_node	*first;
	t_node	*last;

	if (!c || !*c || !(*c)->next)
		return ;
	first = *c;
	*c = first->next;
	last = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_logic *c)
{
	rotate(&c->a);
	c->count[RA]++;
	write(1, "ra\n", 3);
}

void	rb(t_logic *c)
{
	rotate(&c->b);
	c->count[RB]++;
	write(1, "rb\n", 3);
}

void	rr(t_logic *c)
{
	rotate(&c->a);
	rotate(&c->b);
	c->count[RR]++;
	write(1, "rr\n", 3);
}
