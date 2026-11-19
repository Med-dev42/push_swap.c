/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:33:14 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 18:14:34 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	checker_rotate(char *l, t_node **a, t_node **b)
{
	if (!ft_strncmp(l, "ra\n", 4))
		rotate(a);
	else if (!ft_strncmp(l, "rb\n", 4))
		rotate(b);
	else if (!ft_strncmp(l, "rr\n", 4))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(l, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(l, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(l, "rrr\n", 4))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	checker_swap_push(char *l, t_node **a, t_node **b)
{
	if (!ft_strncmp(l, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(l, "sb\n", 4))
		swap(b);
	else if (!ft_strncmp(l, "ss\n", 4))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(l, "pa\n", 4))
		push(b, a);
	else if (!ft_strncmp(l, "pb\n", 4))
		push(a, b);
	else
		return (0);
	return (1);
}

void	checker(t_node **a, t_node **b)
{
	char	buf[5];
	int		r;

	r = read_to_line(buf);
	while (r == 1)
	{
		if (!checker_swap_push(buf, a, b) && !checker_rotate(buf, a, b))
			error_bonus(a, b);
		r = read_to_line(buf);
	}
	if (r < 0)
		error_bonus(a, b);
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	file_engine(ac, av, &a);
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
