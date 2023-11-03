/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:43 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/03 01:46:43 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"
# include "sorting.h"
# include "operations.h"
# include "parsing.h"

int		execute_swap_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_push_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_rotate_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_reverse_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
void	execute_instruction(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
#endif