/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:32:44 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/13 17:35:01 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_max(t_node *a)
{
	t_node	*max;

	max = a;
	while (a)
	{
		if (a->value > max->value)
			max = a;
		a = a->next;
	}
	return (max);
}

t_node	*find_min(t_node *a)
{
	t_node	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}
