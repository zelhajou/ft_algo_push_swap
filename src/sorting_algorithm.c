/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:30:28 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/24 10:56:30 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"

#include "push_swap.h"



void sort_three(t_stack **stack)
{
    if ((*stack)->value > (*stack)->next->value)
    {
        if ((*stack)->next->next && (*stack)->next->value > (*stack)->next->next->value)
        {
            ft_sa(stack);
            ft_rra(stack);
        }
        else if (!(*stack)->next->next || (*stack)->value < (*stack)->next->next->value)
        {
            ft_sa(stack);
        }
        else
        {
            ft_ra(stack);
        }
    }
    else if ((*stack)->next->next && (*stack)->value > (*stack)->next->next->value)
    {
        ft_rra(stack);
    }
}

int find(t_stack *stack, int target)
{
	int i = 0;

	while (stack != NULL)
	{
		if (stack->index == target)
		{
			return i;
		}
		i++;
		stack = stack->next;
	}
	return (-1);
}


void ft_sort(t_stack **stack_a, t_stack **stack_b)
{
    int pv1, pv2;

    if (stack_size(*stack_a) <= 3)
    {
        sort_three(stack_a);
        return;
    }
    pv1 = 0;
	while (stack_size(*stack_a) > 3)
	{
		/* code */
	
    pv2 = stack_size(*stack_a) / 6 + pv1;
    pv1 = pv1 + stack_size(*stack_a) / 3;
	printf("%d\n", pv1);
	while (stack_size(*stack_b) <= pv1)
	{

	if ((*stack_a)->index <= pv1)
		ft_pb(stack_a, stack_b);
	else
		ft_ra(stack_a);

	if (*stack_b != NULL && (*stack_b)->index <= pv2)
		ft_rb(stack_b);
	}
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		if (find(*stack_b, (*stack_a)->index - 1) < stack_size(*stack_b) / 2)
		{
			while ((*stack_b)->index != (*stack_a)->index - 1)
			{
				ft_rb(stack_b);
			}
			ft_pa(stack_a, stack_b);
		}
		else {
		
			while ((*stack_b)->index != (*stack_a)->index - 1)
			{
				ft_rrb(stack_b);
			}
			ft_pa(stack_a, stack_b);

		}
	}


}
