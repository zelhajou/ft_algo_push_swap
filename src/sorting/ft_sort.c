/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:28 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 14:11:46 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

void	ft_shift_partition(t_stack **stack_a, t_stack **stack_b, 
	int pv1, int pv2)
{
	while (ft_stack_size(*stack_b) <= pv1)
	{
		if ((*stack_a)->index <= pv1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		if (*stack_b != NULL && (*stack_b)->index <= pv2)
			ft_rb(stack_b);
	}
}

void	ft_divide_and_shift(t_stack **stack_a, t_stack **stack_b)
{
	int	pv1;
	int	pv2;

	pv1 = 0;
	while (ft_stack_size(*stack_a) > 3)
	{
		pv2 = ft_stack_size(*stack_a) / 6 + pv1;
		pv1 += ft_stack_size(*stack_a) / 3;
		ft_shift_partition(stack_a, stack_b, pv1, pv2);
	}
}

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
