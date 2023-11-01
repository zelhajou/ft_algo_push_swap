/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:01:05 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/01 15:56:15 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2
		&& *stack_a && ft_stack_size(*stack_a) < 2)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("%s", "rr\n");
}
