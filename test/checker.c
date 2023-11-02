/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:15 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 22:42:33 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruction;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	ft_parse_args(argc, argv, &stack_a);
	if (ft_is_sorted(stack_a))
		return (0);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		execute_instruction(instruction, &stack_a, &stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (ft_is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
