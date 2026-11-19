/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:57:33 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:40:02 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_logic *c)
{
	push(&c->b, &c->a);
	c->count[PA]++;
	write(1, "pa\n", 3);
}

void	pb(t_logic *c)
{
	push(&c->a, &c->b);
	c->count[PB]++;
	write(1, "pb\n", 3);
}
