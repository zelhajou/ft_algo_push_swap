/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:11:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/23 12:42:44 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error(1);
	parse_arguments(argc, argv, &stack_a);
	if (!is_sorted(stack_a) && stack_a)
	{
		printf("deja sorted\n");
		free_stack(&stack_a);
		exit(0);
	}

	ft_printf("init stack\n");
	display_list(stack_a);
	
	ft_printf("stack A\n");
	ft_printf("--------------\n");
	display_list(stack_a);

	ft_printf("stack B after push all from A to B\n");
	ft_printf("--------------\n");
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	display_list(stack_b);
	


	ft_printf("stack A after push all from B to A\n");
	ft_printf("--------------\n");
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	display_list(stack_a);
	
	


	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);

}
