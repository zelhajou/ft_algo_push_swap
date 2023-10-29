/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:08:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 12:46:49 by zelhajou         ###   ########.fr       */
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
