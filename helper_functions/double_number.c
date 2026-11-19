/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:08:46 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/13 11:58:42 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	double_number(t_node *stack)
{
	t_node	*all;
	t_node	*helper;

	if (!stack)
		return (0);
	all = stack;
	while (all && all->next)
	{
		helper = all->next;
		while (helper)
		{
			if (helper->value == all->value)
				return (1);
			helper = helper->next;
		}
		all = all->next;
	}
	return (0);
}
