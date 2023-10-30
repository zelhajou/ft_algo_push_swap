/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:34:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/10/29 12:31:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

bool	ft_is_valid_int(const char *str);
bool	ft_is_int_range(const char *str);
bool	ft_has_duplicates(t_stack *stack, int value);
void	ft_add_to_stack(char *token, t_stack **stack_a);
void	ft_handle_token(char *arg, t_stack **stack_a);
#endif