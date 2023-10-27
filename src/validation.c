/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:35 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/23 11:46:44 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_int(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_within_int_range(const char *str)
{
	int	value;

	value = ft_atoi(str);
	if (value >= INT_MIN && value <= INT_MAX)
		return (true);
	return (false);
}

bool	has_duplicates(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	is_sorted(t_stack *stack)
{

	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return 1;
		stack = stack->next;
	}
	return 0;
}

void	parse_arguments(int argc, char *argv[], t_stack **stack_a)
{
	char	**tokens;
	int		value;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (tokens != NULL)
		{
			j = -1;
			while (tokens[++j] != NULL)
			{
				if (is_valid_int(tokens[j]) && is_within_int_range(tokens[j]))
				{
					value = ft_atoi(tokens[j]);
					if (!has_duplicates(*stack_a, value))
						push(stack_a, value);
					else
						ft_error(1);
				}
				else
					ft_error(1);
			}
			free(tokens);
		}
	}
}
