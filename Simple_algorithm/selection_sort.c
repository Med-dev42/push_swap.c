/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 08:14:23 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/11 17:13:35 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	index_node(t_node *a)
{
	int		i;
	int		index;
	t_node	*min;

	if (!a)
		return (0);
	i = 0;
	index = 0;
	min = a;
	while (a)
	{
		if (a->value < min->value)
		{
			index = i;
			min = a;
		}
		i++;
		a = a->next;
	}
	return (index);
}

static int	list_size(t_node *a)
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

static void	rotate_to_top(t_node **a, int index, int size)
{
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			rra(a);
			index--;
		}
	}
}

void	selection_sort(t_node **a, t_node **b)
{
	int	size;
	int	index;

	while (*a)
	{
		size = list_size(*a);
		index = index_node(*a);
		rotate_to_top(a, index, size);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}

/*
#include "../push_swap.h"
#include <stdio.h>

static void     print_list(t_node *a)
{
        while (a)
        {
                printf("%d ", a->value);
                a = a->next;
        }
        printf("\n");
}

static t_node   *new_node(int value)
{
        t_node  *node;

        node = malloc(sizeof(t_node));
        if (!node)
                return (NULL);
        node->value = value;
        node->next = NULL;
        return (node);
}

static void     add_back(t_node **a, t_node *node)
{
        t_node  *last;

        if (!*a)
        {
                *a = node;
                return ;
        }
        last = *a;
        while (last->next)
                last = last->next;
        last->next = node;
}

int     main(int argc, char **argv)
{
        t_node  *a;
        t_node  *b;
        int             i;

        a = NULL;
        b = NULL;
        if (argc < 2)
                return (1);
        i = 1;
        while (i < argc)
        {
                add_back(&a, new_node(atoi(argv[i])));
                i++;
        }
        fprintf(stderr, "before: ");
        print_list(a);
        selection_sort(&a, &b);
        fprintf(stderr, "after:  ");
        print_list(a);
        return (0);
}
*/
