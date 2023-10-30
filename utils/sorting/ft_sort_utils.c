/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:08:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 14:11:50 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	ft_is_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
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
	if (first->value < second->value && second->value < third->value)
		return ;
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

void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b, int value)
{
	while (*stack_a && (*stack_a)->value != value)
		ft_ra(stack_a);
	if (*stack_a)
		ft_pb(stack_a, stack_b);
}

int	ft_find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min1;
	int	min2;

	min1 = ft_find_min(*stack_a);
	ft_push_to_b(stack_a, stack_b, min1);
	min2 = ft_find_min(*stack_a);
	ft_push_to_b(stack_a, stack_b, min2);
	ft_sort_two(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min1;
	int	min2;

	min1 = ft_find_min(*stack_a);
	ft_push_to_b(stack_a, stack_b, min1);
	min2 = ft_find_min(*stack_a);
	ft_push_to_b(stack_a, stack_b, min2);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
