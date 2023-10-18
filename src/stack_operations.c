/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:53:37 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/18 13:07:14 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_putstr_fd("Memory allocation failed", 2);
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	insert_at_beginning(t_node **head, int data)
{
	t_node	*ptr;

	ptr = create_node(data);
	ptr->next = *head;
	*head = ptr;
}

void	insert_at_end(t_node **head, int data)
{
	t_node	*current;
	t_node	*new_node;

	current = *head;
	new_node = create_node(data);
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	del_first_node(t_node **head)
{
	t_node	*temp;

	temp = *head;
	if (temp == NULL)
		ft_printf("List is already empty");
	else
	{
		*head = (*head)->next;
		free(temp);
	}
}

void	del_last_node(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		ft_printf("List is already empty!");
	else if (temp->next == NULL)
	{
		free (temp);
		temp = NULL;
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free (temp->next);
		temp->next = NULL;
	}
}
