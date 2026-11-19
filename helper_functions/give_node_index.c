/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_node_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:16:41 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/13 08:25:25 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_node_index(t_node *stack)
{
	t_node	*all;
	t_node	*node;
	int		n;

	all = stack;
	while (all)
	{
		node = stack;
		n = 0;
		while (node)
		{
			if (node->value < all->value)
				n++;
			node = node->next;
		}
		all->index = n;
		all = all->next;
	}
}
