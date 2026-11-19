/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 08:14:23 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 10:27:36 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	index_node(t_node *a)
{
	int		i;
	int		index;
	t_node	*min;

	if (!a)
		return (0);
	i = 0;
	index = 0;
	min = a;
	while (a)
	{
		if (a->value < min->value)
		{
			index = i;
			min = a;
		}
		i++;
		a = a->next;
	}
	return (index);
}

static void	rotate_to_top(t_logic *c, int index, int size)
{
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(c);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			rra(c);
			index--;
		}
	}
}

void	selection_sort(t_logic *c)
{
	int	size;
	int	index;

	while (c->a)
	{
		size = size_list(c->a);
		index = index_node(c->a);
		rotate_to_top(c, index, size);
		pb(c);
	}
	while (c->b)
		pa(c);
}
