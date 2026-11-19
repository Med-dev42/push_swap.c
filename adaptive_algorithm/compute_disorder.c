/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:28:32 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/14 10:47:39 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compute_disorder(t_node *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0);
	return ((int)(mistakes * 10000 / total));
}
