/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:57:58 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 18:16:57 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
}
