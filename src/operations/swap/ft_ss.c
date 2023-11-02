/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:44:03 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 21:44:25 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && ft_stack_size(*stack_a) < 2)
		&& (*stack_b && ft_stack_size(*stack_b) < 2))
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
