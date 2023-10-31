/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:35 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/31 14:20:09 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_add_to_stack(char *token, t_stack **stack_a)
{
	int	value;

	if (!token || *token == '\0')
		ft_error(1);
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

	if (!arg || !*arg)
		ft_error(1);
	if (ft_str_is_whitespace(arg))
		ft_error(1);
	tokens = ft_split(arg, ' ');
	if (tokens != NULL)
	{
		j = -1;
		while (tokens[++j] != NULL)
			ft_add_to_stack(tokens[j], stack_a);
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
}

void	ft_parse_args(int argc, char *argv[], t_stack **stack_a)
{
	int		i;

	i = 0;
	while (++i < argc)
		ft_handle_token(argv[i], stack_a);
	ft_assign_indexes(stack_a);
}
