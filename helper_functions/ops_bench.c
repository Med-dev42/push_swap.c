/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bench.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:35:33 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 08:56:20 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_one(char *name, int n)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(" ", 2);
}

void	print_ops(t_logic *c)
{
	ft_putstr_fd("[bench] ", 2);
	print_one("sa", c->count[SA]);
	print_one("sb", c->count[SB]);
	print_one("ss", c->count[SS]);
	print_one("pa", c->count[PA]);
	print_one("pb", c->count[PB]);
	ft_putstr_fd("\n[bench] ", 2);
	print_one("ra", c->count[RA]);
	print_one("rb", c->count[RB]);
	print_one("rr", c->count[RR]);
	print_one("rra", c->count[RRA]);
	print_one("rrb", c->count[RRB]);
	print_one("rrr", c->count[RRR]);
	ft_putstr_fd("\n", 2);
}
