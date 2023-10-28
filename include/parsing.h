/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:34:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/28 20:09:51 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

bool	ft_is_valid_int(const char *str);
bool	ft_is_within_int_range(const char *str);
bool	ft_has_duplicates(t_stack *stack, int value);
bool	ft_is_sorted(t_stack *stack);

#endif