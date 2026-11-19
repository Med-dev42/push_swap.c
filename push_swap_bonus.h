/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:31:48 by mlazar            #+#    #+#             */
/*   Updated: 2026/11/17 10:43:20 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void	error_bonus(t_node **a, t_node **b);
void	checker(t_node **a, t_node **b);
int		checker_swap_push(char *l, t_node **a, t_node **b);
int		checker_rotate(char *l, t_node **a, t_node **b);
int		read_to_line(char *buf);

#endif
