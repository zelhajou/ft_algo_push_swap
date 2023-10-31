/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:13 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 01:30:15 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"

void	ft_move_top_elements_to_a(t_stack **stack_a, t_stack **stack_b,
		int last_idx_a)
{
	while ((*stack_b)->index != (*stack_a)->index - 1)
	{
		if ((*stack_b)->index > last_idx_a)
		{
			last_idx_a = (*stack_b)->index;
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a);
		}
		else
			ft_rb(stack_b);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_move_bottom_elements_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->index != (*stack_a)->index - 1)
		ft_rrb(stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_move_element_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	last_idx_a;

	last_idx_a = 0;
	if (ft_get_tail_index(*stack_a) < (*stack_a)->index)
		last_idx_a = ft_get_tail_index(*stack_a);
	if (ft_find_index(*stack_b, (*stack_a)->index - 1)
		< ft_stack_size(*stack_b) / 2)
		ft_move_top_elements_to_a(stack_a, stack_b, last_idx_a);
	else
		ft_move_bottom_elements_to_a(stack_a, stack_b);
}

void	ft_partition_and_move(t_stack **stack_a, t_stack **stack_b,
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

void	ft_divide_and_move(t_stack **stack_a, t_stack **stack_b)
{
	int	pv1;
	int	size;

	pv1 = 0;
	while (ft_stack_size(*stack_a) > 3)
	{
		size = ft_stack_size(*stack_a) / 3;
		if (!size)
			size = ft_stack_size(*stack_a) - 3;
		ft_partition_and_move(stack_a, stack_b, pv1, size);
		pv1 += size;
	}
}
