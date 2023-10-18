/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:36:40 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/18 13:09:42 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H

# include "push_swap.h"

t_node	*create_node(int data);
void	insert_at_beginning(t_node **head, int data);
void	insert_at_end(t_node **head, int data);
void	insert_at_position(t_node **head, int data, int pos);

void	del_first_node(t_node **head);
void	del_last_node(t_node *head);
void	free_list(t_node *head);

void	display_list(t_node *head);
void	count_of_nodes(t_node *head);

#endif
