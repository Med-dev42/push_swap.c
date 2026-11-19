/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 10:58:09 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/18 08:10:17 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_logic *c)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	give_node_index(c->a);
	size = size_list(c->a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((c->a->index >> i) & 1) == 1)
				ra(c);
			else
				pb(c);
		}
		while (c->b)
			pa(c);
	}
}
