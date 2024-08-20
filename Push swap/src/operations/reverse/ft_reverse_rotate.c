/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:21 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 10:25:06 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}
