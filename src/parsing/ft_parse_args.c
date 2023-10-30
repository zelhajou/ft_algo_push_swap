/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:35 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 12:36:50 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_parse_args(int argc, char *argv[], t_stack **stack_a)
{
	int		i;

	i = 0;
	while (++i < argc)
		ft_handle_token(argv[i], stack_a);
	ft_assign_indexes(stack_a);
}
