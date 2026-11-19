/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alot_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:06:04 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/15 08:54:49 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_flag(char *s, int *mode, int *bench)
{
	if (!ft_strncmp(s, "--simple", 9))
		*mode = SIMPLE;
	else if (!ft_strncmp(s, "--medium", 9))
		*mode = MEDIUM;
	else if (!ft_strncmp(s, "--complex", 10))
		*mode = COMPLEX;
	else if (!ft_strncmp(s, "--adaptive", 11))
		*mode = ADAPTIVE;
	else if (!ft_strncmp(s, "--bench", 8))
		*bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int ac, char **av, t_logic *c, int *bench)
{
	int	i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!get_flag(av[i], &c->mode, bench))
			error(&c->a);
		i++;
	}
	return (i);
}
