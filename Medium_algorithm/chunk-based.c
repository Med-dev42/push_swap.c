/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk-based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:48:26 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/11 17:11:23 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_index(t_node *a)
{
	t_node	*head;
	t_node	*other;
	int		count;

	if (!a)
		return ;
	head = a;
	while (a)
	{
		count = 0;
		other = head;
		while (other)
		{
			if (other->value < a->value)
				count++;
			other = other->next;
		}
		a->index = count;
		a = a->next;
	}
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

void	push_numbergroup_to_b(t_node **a, t_node **b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index < pushed + chunk)
		{
			pb(a, b);
			if ((*b)->index < pushed)
				rb(b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	push_numbergroup_to_a(t_node **a, t_node **b)
{
	int	size;
	int	bigger;

	while (*b)
	{
		size = stack_size(*b);
		bigger = found_bigger_b(*b);
		if (bigger <= size / 2)
		{
			while (bigger-- > 0)
				rb(b);
		}
		else
		{
			while (bigger++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	give_index(*a);
	push_numbergroup_to_b(a, b, calculator_n(stack_size(*a)));
	push_numbergroup_to_a(a, b);
}
