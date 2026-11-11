/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:08:03 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/11 17:12:16 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculator_n(int n)
{
	int	chunk;

	if (n <= 100)
		chunk = n / 5;
	else
		chunk = n / 15;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

int	list_size(t_node *a)
{
	int	len;

	if (!a)
		return (0);
	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}
