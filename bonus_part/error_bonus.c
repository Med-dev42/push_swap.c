/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:52:38 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 10:42:12 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	error_bonus(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	read_to_line(char *buf)
{
	int		i;
	int		r;
	char	c;

	i = 0;
	r = read(0, &c, 1);
	while (r > 0)
	{
		if (c == '\n')
		{
			buf[i++] = '\n';
			buf[i] = '\0';
			return (1);
		}
		if (i >= 3)
			return (-1);
		buf[i++] = c;
		r = read(0, &c, 1);
	}
	if (r < 0 || i > 0)
		return (-1);
	return (0);
}
