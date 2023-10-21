/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:33:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/21 18:44:22 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to push an element onto the stack.
void	push(t_stack **stack, int value) {
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

// Function to pop an element from the stack.
// int pop(Stack* stack) {
//     // Implement pop operation here.
//     return 0; // Replace with actual implementation.
// }

// Function to swap the top two elements of the stack.
// void swap(Stack* stack) {
//     // Implement swap operation here.
// }

// Function to rotate the stack in a certain direction.
// void rotate(Stack* stack, char direction) {
//     // Implement rotate operation here.
// }
