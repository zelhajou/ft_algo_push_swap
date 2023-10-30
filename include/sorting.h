/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:24:41 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 12:56:02 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "push_swap.h"

bool	ft_is_sorted(t_stack *stack);
int		ft_find_index(t_stack *stack, int target);
void	ft_sort_two(t_stack **stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int		ft_find_min(t_stack *stack);
void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b, int value);
void	ft_partition_and_shift(t_stack **stack_a, t_stack **stack_b,
			int pv1, int pv2);
void	ft_divide_and_shift(t_stack **stack_a, t_stack **stack_b);
void	ft_move_element_to_a(t_stack **stack_a, t_stack **stack_b);

#endif