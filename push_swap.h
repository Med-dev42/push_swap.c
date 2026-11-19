/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:43:25 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 11:00:38 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define OP_COUNT 11

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

typedef struct s_logic
{
	t_node	*a;
	t_node	*b;
	int		count[11];
	int		disorder;
	int		mode;
	int		used;
}	t_logic;

void	swap(t_node **a);
void	sa(t_logic *c);
void	sb(t_logic *c);
void	ss(t_logic *c);

void	push(t_node **a, t_node **b);
void	pa(t_logic *c);
void	pb(t_logic *c);

void	rotate(t_node **c);
void	ra(t_logic *c);
void	rb(t_logic *c);
void	rr(t_logic *c);

void	reverse_rotate(t_node **x);
void	rra(t_logic *c);
void	rrb(t_logic *c);
void	rrr(t_logic *c);

void	sort_five(t_logic *c);
void	sort_three(t_logic *c);
int		size_list(t_node *a);
t_node	*new_node(int num);
void	move_min_to_top(t_logic *c);
int		is_sorted(t_node *stack);
int		is_number(char *s);
void	give_node_index(t_node *stack);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
void	free_stack(t_node **x);
t_node	*find_min(t_node *a);
t_node	*find_max(t_node *a);
void	file_engine(int ac, char **av, t_node **a);
void	error(t_node **a);
int		double_number(t_node *stack);
int		parse_flags(int ac, char **av, t_logic *c, int *bench);
void	run_alhgr(t_logic *c);
void	add_back(t_node **node, t_node *new);
int		compute_disorder(t_node *a);
void	print_bench(t_logic *c);
void	print_ops(t_logic *c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

void	selection_sort(t_logic *c);

void	chunk_sort(t_logic *c);
int		size_list(t_node *a);
int		square_root(int n);

void	radix_sort(t_logic *c);

#endif
