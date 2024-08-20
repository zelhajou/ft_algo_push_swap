/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:00:17 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/01 15:42:33 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_ra(t_stack **stack_a)
{
	if (*stack_a && ft_stack_size(*stack_a) < 2)
		return ;
	ft_rotate(stack_a);
	ft_printf("%s", "ra\n");
}
