/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:49:13 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:23:29 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_logic *c)
{
	t_node	*max;

	max = find_max(c->a);
	if (c->a == max)
		ra(c);
	else if (c->a->next == max)
		rra(c);
	if (c->a->value > c->a->next->value)
		sa(c);
}

void	sort_five(t_logic *c)
{
	while (size_list(c->a) > 3)
	{
		move_min_to_top(c);
		pb(c);
	}
	sort_three(c);
	while (c->b)
		pa(c);
}
