/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:12:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 12:45:01 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_is_valid_int(const char *str)
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

bool	ft_is_int_range(const char *str)
{
	int	value;

	value = ft_atoi(str);
	if (value >= INT_MIN && value <= INT_MAX)
		return (true);
	return (false);
}

bool	ft_has_duplicates(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	ft_add_to_stack(char *token, t_stack **stack_a)
{
	int	value;

	if (ft_is_valid_int(token) && ft_is_int_range(token))
	{
		value = ft_atoi(token);
		if (!ft_has_duplicates(*stack_a, value))
			ft_push(stack_a, value);
		else
			ft_error(1);
	}
	else
		ft_error(1);
}

void	ft_handle_token(char *arg, t_stack **stack_a)
{
	char	**tokens;
	int		j;
	int		i;

	tokens = ft_split(arg, ' ');
	if (tokens != NULL)
	{
		j = -1;
		while (tokens[++j] != NULL)
			ft_add_to_stack(tokens[j], stack_a);
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
	}
}
