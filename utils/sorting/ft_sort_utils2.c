/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:33:25 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/30 23:11:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sorting.h"

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
