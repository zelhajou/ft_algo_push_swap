/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:12:14 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 14:23:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

bool	ft_str_is_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_is_whitespace(*str))
			return (false);
		str++;
	}
	return (true);
}

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
