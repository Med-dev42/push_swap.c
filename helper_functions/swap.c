/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:20:57 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:03:43 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **n)
{
	t_node	*first;
	t_node	*second;

	if (!n || !*n || !(*n)->next)
		return ;
	first = *n;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*n = second;
}

void	sa(t_logic *c)
{
	swap(&c->a);
	c->count[SA]++;
	write(1, "sa\n", 3);
}

void	sb(t_logic *c)
{
	swap(&c->b);
	c->count[SB]++;
	write(1, "sb\n", 3);
}

void	ss(t_logic *c)
{
	swap(&c->a);
	swap(&c->b);
	c->count[SS]++;
	write(1, "ss\n", 3);
}
