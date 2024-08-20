/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:00:04 by zelhajou          #+#    #+#             */
/*   Updated: 2023/11/02 19:10:08 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Include header files
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// Define the data structure
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;

}	t_stack;

void	ft_pushlst(t_stack **stack, int value);
void	ft_assign_indexes(t_stack **stack_a);
int		ft_stack_size(t_stack *stack);
int		ft_get_tail_index(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_parse_args(int argc, char *argv[], t_stack **stack_a);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
/* void	ft_display_list(t_stack *head); */
#endif