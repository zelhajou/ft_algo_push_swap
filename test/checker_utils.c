/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 22:38:19 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_swap_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		ft_swap(stack_a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		ft_swap(stack_b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

void	execute_push_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instruction, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		ft_push(stack_a, stack_b);
}

void	execute_rotate_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instruction, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
	{
		if (*stack_b && ft_stack_size(*stack_b) < 2
			&& *stack_a && ft_stack_size(*stack_a) < 2)
			return ;
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	execute_reverse_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instruction, "rra\n") == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
	{
		if (*stack_a && (ft_stack_size(*stack_a) < 2)
			&& *stack_b && (ft_stack_size(*stack_b) < 2))
			return ;
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}

void	execute_instruction(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	execute_swap_instructions(instruction, stack_a, stack_b);
	execute_push_instructions(instruction, stack_a, stack_b);
	execute_rotate_instructions(instruction, stack_a, stack_b);
	execute_reverse_instructions(instruction, stack_a, stack_b);
}
