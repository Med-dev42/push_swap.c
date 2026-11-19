/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:36:32 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/13 10:37:44 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	*mall_word(const char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	*free_all(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	helper_fun(char const *s, char c, int *i)
{
	while (s[*i] != '\0' && s[*i] == c)
		(*i)++;
	if (s[*i] != '\0')
		return (1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (helper_fun(s, c, &i))
	{
		res[j] = mall_word(&s[i], c);
		if (!res[j])
			return (free_all(res, j));
		while (s[i] != '\0' && s[i] != c)
			i++;
		j++;
	}
	res[j] = NULL;
	return (res);
}
