/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:24:41 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 21:39:50 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
#define SORTING_H

# include "push_swap.h"

int	ft_find_index(t_stack *stack, int target);
void	ft_sort_top_three(t_stack **stack);
void	ft_shift_partition(t_stack **stack_a, t_stack **stack_b, int pv1, int pv2);
void	ft_divide_and_shift(t_stack **stack_a, t_stack **stack_b);
void	ft_shift_b_to_a(t_stack **stack_a, t_stack **stack_b);

#endif