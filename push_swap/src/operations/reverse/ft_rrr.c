/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:38:29 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 21:43:17 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && ft_stack_size(*stack_a) < 2)
		&& (*stack_b && ft_stack_size(*stack_b) < 2))
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("%s", "rrr\n");
}
