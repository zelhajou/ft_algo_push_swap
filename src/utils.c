/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:33:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/24 10:54:30 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function to push an element onto the stack. */
void	push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		ft_error(0);
	new_node->value = value;
	new_node->next = NULL;
	
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void	display_list(t_stack *head)
{
	t_stack *temp;

	temp = head;
	if (temp == NULL)
		ft_printf("LinkedList is empty");
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void	free_stack(t_stack **stack_a)
{
	t_stack *temp;

	while (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
}
