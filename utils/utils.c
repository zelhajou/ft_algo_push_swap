/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:33:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 16:29:26 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack, int value)
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
			temp = temp->next;
		temp->next = new_node;
	}
}

void	ft_assign_indexes(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		index;

	current = *stack_a;
	while (current)
	{
		tmp = *stack_a;
		index = 0;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_free_stack(t_stack **stack_a)
{
	t_stack	*temp;

	while (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	ft_get_tail_index(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}

/*
void	ft_display_list(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (temp == NULL)
		ft_printf("LinkedList is empty");
	while (temp != NULL)
	{
		ft_printf("%d - index : %d\n", temp->value, temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
}
*/