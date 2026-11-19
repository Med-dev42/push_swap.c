/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghrithm_use.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:06:57 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 11:49:15 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	choose(int disorder)
{
	if (disorder < 2000)
		return (SIMPLE);
	if (disorder < 5000)
		return (MEDIUM);
	return (COMPLEX);
}

void	run_alhgr(t_logic *c)
{
	if (c->mode == ADAPTIVE)
		c->used = choose(c->disorder);
	else
		c->used = c->mode;
	if (is_sorted(c->a))
		return ;
	if (c->mode == ADAPTIVE && size_list(c->a) <= 5)
	{
		c->used = SIMPLE;
		sort_five(c);
		return ;
	}
	if (c->used == SIMPLE)
		selection_sort(c);
	else if (c->used == MEDIUM)
		chunk_sort(c);
	else
		radix_sort(c);
}
