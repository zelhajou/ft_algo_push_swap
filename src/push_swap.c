/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:11:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 21:22:30 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error(1);
	ft_parse_args(argc, argv, &stack_a);
	ft_assign_indexes(&stack_a);



	ft_printf("init stack\n");
	ft_display_list(stack_a);
	
	ft_sort(&stack_a, &stack_b);

	ft_printf("stack A\n--------------\n");
	ft_display_list(stack_a);
	ft_printf("stack B\n--------------\n");
	ft_display_list(stack_b);

	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);

}
