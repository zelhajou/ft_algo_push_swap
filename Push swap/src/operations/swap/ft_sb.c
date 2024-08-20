/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:42:30 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:07 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_sb(t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2)
		return ;
	ft_swap(stack_b);
	ft_printf("sb\n");
}
