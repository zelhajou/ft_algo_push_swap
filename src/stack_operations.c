/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:53:37 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/22 19:57:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operations.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return;
	t_stack *temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return;
	t_stack *temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	sa(t_stack **stack_a)
{	
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	int temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
}

void	sb(t_stack **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	int temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void rotate(t_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_stack *temp = *stack;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = *stack;
    *stack = (*stack)->next;
    temp->next->next = NULL;
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void reverse_rotate(t_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_stack *temp = *stack;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    t_stack *last = temp->next;
    temp->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}