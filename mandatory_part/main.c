/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 09:20:28 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 08:50:39 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_logic(t_logic *c)
{
	int	i;

	c->a = NULL;
	c->b = NULL;
	c->disorder = 0;
	c->mode = ADAPTIVE;
	c->used = ADAPTIVE;
	i = 0;
	while (i < 11)
		c->count[i++] = 0;
}

int	main(int ac, char **av)
{
	t_logic	c;
	int		bench;
	int		start;

	if (ac < 2)
		return (0);
	bench = 0;
	init_logic(&c);
	start = parse_flags(ac, av, &c, &bench);
	if (start >= ac)
		return (0);
	file_engine(ac - start + 1, av + start - 1, &c.a);
	c.disorder = compute_disorder(c.a);
	run_alhgr(&c);
	if (bench)
		print_bench(&c);
	free_stack(&c.a);
	return (0);
}
