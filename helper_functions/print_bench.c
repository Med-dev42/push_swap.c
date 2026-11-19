/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:34:52 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 08:55:58 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(int d)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(d / 100, 2);
	write(2, ".", 1);
	if (d % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(d % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_class(int s)
{
	if (s == SIMPLE)
		ft_putstr_fd("O(n^2)", 2);
	else if (s == MEDIUM)
		ft_putstr_fd("O(n sqrt(n))", 2);
	else
		ft_putstr_fd("O(n log n)", 2);
}

static void	print_strategy(t_logic *c)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (c->mode == ADAPTIVE)
		ft_putstr_fd("Adaptive", 2);
	else if (c->mode == SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (c->mode == MEDIUM)
		ft_putstr_fd("Medium", 2);
	else
		ft_putstr_fd("Complex", 2);
	ft_putstr_fd(" / ", 2);
	print_class(c->used);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_logic *c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
		total += c->count[i++];
	print_disorder(c->disorder);
	print_strategy(c);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_ops(c);
}
