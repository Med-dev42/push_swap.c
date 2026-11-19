/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:08:40 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 18:18:49 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (s[i] == '\0');
}

void	free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static char	*join_args(int ac, char **av)
{
	int		i;
	char	*all;
	char	*tmp;

	i = 1;
	all = ft_strdup("");
	while (all && i < ac)
	{
		if (only_spaces(av[i]))
		{
			free(all);
			return (NULL);
		}
		tmp = ft_strjoin(all, av[i]);
		free(all);
		if (!tmp)
			return (NULL);
		all = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (all);
}

static void	fill_stack(char **res, t_node **a)
{
	int		i;
	long	n;
	t_node	*node;

	i = 0;
	while (res[i])
	{
		n = ft_atol(res[i]);
		if (!is_number(res[i]) || n > INT_MAX || n < INT_MIN)
		{
			free_split(res);
			error(a);
		}
		node = new_node((int)n);
		if (!node)
		{
			free_split(res);
			error(a);
		}
		add_back(a, node);
		i++;
	}
}

void	file_engine(int ac, char **av, t_node **a)
{
	char	*res_join;
	char	**res;

	res_join = join_args(ac, av);
	if (!res_join)
		error(a);
	res = ft_split(res_join, ' ');
	free(res_join);
	if (!res || !res[0])
	{
		free_split(res);
		error(a);
	}
	fill_stack(res, a);
	free_split(res);
	if (double_number(*a))
		error(a);
}
