/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:30:59 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/18 13:07:04 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	insert_at_position(t_node **head, int data, int pos)
{
	t_node	*ptr;
	t_node	*new_node;

	ptr = *head;
	new_node = create_node(data);
	pos--;
	while (pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
}

void	display_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		ft_printf("LinkedList is empty");
	while (temp != NULL)
	{
		ft_printf("%d -> ", temp->data);
		temp = temp->next;
	}
	ft_printf("Null\n");
}

void	count_of_nodes(t_node *head)
{
	int		count;
	t_node	*ptr;

	count = 0;
	ptr = head;
	if (ptr == NULL)
		ft_printf("LinkedList is empty");
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	ft_printf("%d", count);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
}
