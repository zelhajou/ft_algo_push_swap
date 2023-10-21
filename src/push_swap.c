/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:11:09 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/21 18:54:46 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	// Check if the number of arguments is valid.
	if (argc < 2)
    {
        ft_putstr_fd("Error: No input.\n", 2);
        return 1;
    }
	// Parse command line arguments and initialize stacks.
	t_stack *stack_a = parse_arguments(argc, argv);

    printf("Parsed and Validated Integers: ");
    t_stack *current = stack_a;
    while (current != NULL)
    {

        printf("%d ", current->value);
        current = current->next;
	
	}
	printf("\n");
    while (stack_a != NULL)
    {
        t_stack *temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }
    // Call your sorting function (e.g., sort).
    // Print the required operations to sort the stack.
    // Cleanup and free memory.
	return 0;
}
