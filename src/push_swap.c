/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:11:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/22 20:52:41 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	sb(&stack_a, &stack_b);
	ft_printf("stack A\n");
	display_list(stack_a);
	display_list(stack_a);

	ft_printf("stack B\n");
	display_list(stack_b);
	display_list(stack_b);


	free_stack(&stack_b);
	return (0);

}
