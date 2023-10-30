/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:13 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/30 18:05:44 by zelhajou         ###   ########.fr       */
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
	int	tail_a;

	tail_a = 0;
	if (ft_tail_index(*stack_a) < (*stack_a)->index)
		tail_a = ft_tail_index(*stack_a);
	if (ft_find_index(*stack_b, (*stack_a)->index - 1)
		< ft_stack_size(*stack_b) / 2)
	{
		while ((*stack_b)->index != (*stack_a)->index - 1)
		{
			if ((*stack_b)->index > tail_a)
			{
				tail_a = (*stack_b)->index;
				ft_pa(stack_a, stack_b);
				ft_ra(stack_a);
			}
			else
				ft_rb(stack_b);
		}
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
	int pv1, int size)
{
	while (ft_stack_size(*stack_b) <= pv1 + size)
	{
		if ((*stack_a)->index <= pv1 + size)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		if (*stack_b != NULL && (*stack_b)->index
			<= pv1 + size / 2 && (*stack_b)->index > pv1)
			ft_rb(stack_b);
	}
}

void	ft_divide_and_shift(t_stack **stack_a, t_stack **stack_b)
{
	int	pv1;
	int	size;

	pv1 = 0;
	while (ft_stack_size(*stack_a) > 3)
	{
		size = ft_stack_size(*stack_a) / 3;
		if (!size)
			size = ft_stack_size(*stack_a) - 3;
		ft_partition_and_shift(stack_a, stack_b, pv1, size);
		pv1 += size;
	}
}
