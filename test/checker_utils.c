/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:22 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 19:50:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_swap_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

void	execute_push_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instruction, "pa", 2) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		ft_push(stack_a, stack_b);
}

void	execute_rotate_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instruction, "ra", 2) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

void	execute_reverse_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(instruction, "rra", 2) == 0)
		ft_printf("%s\n", instruction);
	else if (ft_strncmp(instruction, "rrb", 2) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(instruction, "rrr", 2) == 0)
	{
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
