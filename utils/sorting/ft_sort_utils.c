/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:08:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 01:29:52 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b, int value)
{
	while (*stack_a && (*stack_a)->value != value)
		ft_ra(stack_a);
	if (*stack_a)
		ft_pb(stack_a, stack_b);
}

void	ft_sort_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	if (first->value > second->value)
		ft_sa(stack);
}

void	handle_sorting_cases(t_stack **stack, t_stack *first,
		t_stack *second, t_stack *third)
{
	if (first->value > second->value && first->value > third->value)
	{
		ft_ra(stack);
		if (second->value > third->value)
			ft_sa(stack);
		return ;
	}
	if (second->value > first->value && first->value > third->value)
	{
		ft_rra(stack);
		return ;
	}
	if (second->value > first->value && second->value > third->value)
	{
		ft_sa(stack);
		ft_ra(stack);
		return ;
	}
	if (third->value > first->value && third->value > second->value)
	{
		if (first->value > second->value)
			ft_sa(stack);
		return ;
	}
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	if (ft_is_sorted(*stack))
		return ;
	handle_sorting_cases(stack, first, second, third);
}
