/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:28 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 21:55:13 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_is_sorted(*stack_a) && *stack_a)
	{
		ft_free_stack(stack_a);
		exit(0);
	}
	if (ft_stack_size(*stack_a) <= 3)
	{
		ft_sort_top_three(stack_a);
		return ;
	}
	ft_divide_and_shift(stack_a, stack_b);
	ft_sort_top_three(stack_a);
	while (*stack_b)
		ft_shift_b_to_a(stack_a, stack_b);
}
