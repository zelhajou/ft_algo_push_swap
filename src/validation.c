/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:35 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/21 18:55:35 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_valid_int(const char *str)
{
    if (*str == '-' || *str == '+')
        str++; // Move past the sign character

    while (*str)
    {
        if (!ft_isdigit(*str))
            return false;
        str++;
    }
    return true;
}

bool is_within_int_range(const char *str)
{
	int value;

	value = ft_atoi(str);
	return value >= INT_MIN && value <= INT_MAX;
}

bool has_duplicates(t_stack *stack, int value)
{
    while (stack != NULL)
    {
        if (stack->value == value)
            return true;
        stack = stack->next;
    }
    return false;
}

t_stack *parse_arguments(int argc, char *argv[])
{
    t_stack *stack_a;

	stack_a = NULL;
    for (int i = 1; i < argc; i++)
    {
		char **tokens = ft_split(argv[i], ' ');

		if (tokens != NULL)
        {
            for (int j = 0; tokens[j] != NULL; j++)
            {
                if (is_valid_int(tokens[j]) && is_within_int_range(tokens[j]))
                {
                    int value = ft_atoi(tokens[j]);
                    if (!has_duplicates(stack_a, value))
						push(&stack_a, value);
					else
                        ft_error(1);
                }
                else
					    ft_error(1);
            }
            free(tokens);
        }
    }
    return stack_a;
}
