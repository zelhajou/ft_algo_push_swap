/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:42 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 14:20:28 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rb(t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2)
		return ;
	ft_rotate(stack_b);
	ft_printf("%s", "rb\n");
}
