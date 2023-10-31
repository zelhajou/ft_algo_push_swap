/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:28 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 01:24:27 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

void	handle_large_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_divide_and_move(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_move_element_to_a(stack_a, stack_b);
		while (ft_get_tail_index(*stack_a) == (*stack_a)->index - 1)
			ft_rra(stack_a);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
	{
		ft_sort_two(stack_a);
		return ;
	}
	else if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	else if (size == 4)
	{
		ft_sort_four(stack_a, stack_b);
		return ;
	}
	else if (size == 5)
	{
		ft_sort_five(stack_a, stack_b);
		return ;
	}
	else
		handle_large_sort(stack_a, stack_b);
}
