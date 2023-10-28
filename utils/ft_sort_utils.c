/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:08:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 22:00:37 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_sort_top_three(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		if ((*stack)->next->next
			&& (*stack)->next->value > (*stack)->next->next->value)
		{
			ft_sa(stack);
			ft_rra(stack);
		}
		else if (!(*stack)->next->next
			|| (*stack)->value < (*stack)->next->next->value)
			ft_sa(stack);
		else
			ft_ra(stack);
	}
	else if ((*stack)->next->next
		&& (*stack)->value > (*stack)->next->next->value)
		ft_rra(stack);
}

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

void	ft_shift_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_find_index(*stack_b, (*stack_a)->index - 1) < ft_stack_size(*stack_b) / 2)
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

void	ft_shift_partition(t_stack **stack_a, t_stack **stack_b, int pv1, int pv2)
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