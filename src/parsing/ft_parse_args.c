/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:35 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 20:52:07 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

void	ft_parse_args(int argc, char *argv[], t_stack **stack_a)
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
				if (ft_is_valid_int(tokens[j]) && ft_is_within_int_range(tokens[j]))
				{
					value = ft_atoi(tokens[j]);
					if (!ft_has_duplicates(*stack_a, value))
						ft_push(stack_a, value);
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
