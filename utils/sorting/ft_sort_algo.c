/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:13 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/30 13:55:43 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	ft_find_index(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	ft_move_element_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_find_index(*stack_b, (*stack_a)->index - 1)
		< ft_stack_size(*stack_b) / 2)
	{
		while ((*stack_b)->index != (*stack_a)->index - 1)
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->index != (*stack_a)->index - 1)
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
	}
}

void	ft_partition_and_shift(t_stack **stack_a, t_stack **stack_b,
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
		ft_partition_and_shift(stack_a, stack_b, pv1, pv2);
	}
}
