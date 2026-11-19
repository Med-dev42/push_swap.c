/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_numb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 07:58:52 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:25:39 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_min_to_top(t_logic *c)
{
	t_node	*min;
	t_node	*tmp;
	int		pos;

	min = find_min(c->a);
	tmp = c->a;
	pos = 0;
	while (tmp != min)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size_list(c->a) / 2)
	{
		while (c->a != min)
			ra(c);
	}
	else
	{
		while (c->a != min)
			rra(c);
	}
}
