/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:48:26 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:20:57 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	square_root(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

int	found_bigger_b(t_node *b)
{
	int		i;
	int		index;
	t_node	*big;

	if (!b)
		return (0);
	i = 0;
	index = 0;
	big = b;
	while (b)
	{
		if (b->value > big->value)
		{
			index = i;
			big = b;
		}
		i++;
		b = b->next;
	}
	return (index);
}

void	push_numbergroup_to_b(t_logic *c, int chunk)
{
	int	pushed;

	pushed = 0;
	while (c->a)
	{
		if (c->a->index < pushed + chunk)
		{
			pb(c);
			if (c->b->index < pushed)
				rb(c);
			pushed++;
		}
		else
			ra(c);
	}
}

void	push_numbergroup_to_a(t_logic *c)
{
	int	size;
	int	bigger;

	while (c->b)
	{
		size = size_list(c->b);
		bigger = found_bigger_b(c->b);
		if (bigger <= size / 2)
		{
			while (bigger-- > 0)
				rb(c);
		}
		else
		{
			while (bigger++ < size)
				rrb(c);
		}
		pa(c);
	}
}

void	chunk_sort(t_logic *c)
{
	give_node_index(c->a);
	push_numbergroup_to_b(c, square_root(size_list(c->a)));
	push_numbergroup_to_a(c);
}
