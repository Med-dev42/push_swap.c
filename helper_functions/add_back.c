/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 07:52:21 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/13 08:00:07 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!node || !new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	last = *node;
	while (last->next)
		last = last->next;
	last->next = new;
}
